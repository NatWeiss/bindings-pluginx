#include "jsb_pluginx_basic_conversions.h"
#include <math.h>

#include "jsb_pluginx_spidermonkey_specifics.h"
#include "pluginxUTF8.h"

namespace pluginx {

// just a simple utility to avoid mem leaking when using JSString
class JSStringWrapper
{
    JSString*   string;
    const char* buffer;
    JSContext* cx;
public:
    JSStringWrapper() {
        buffer = NULL;
    }
    JSStringWrapper(JSString* str, JSContext* cx) {
        set(str, cx);
    }
    JSStringWrapper(jsval val, JSContext* cx) {
        set(val, cx);
    }
    ~JSStringWrapper() {
        if (buffer) {
            // delete[] buffer;
            // buffer = NULL;
            JS_free(cx, (void*)buffer);
        }
    }
    void set(jsval val, JSContext* cx) {
        if (val.isString()) {
            this->set(val.toString(), cx);
        } else {
            buffer = NULL;
        }
    }
    void set(JSString* str, JSContext* cx) {
        this->cx = cx;
        string = str;
        // Not suppored in SpiderMonkey v19
        //buffer = JS_EncodeString(cx, string);
        
        const jschar *chars = JS_GetStringCharsZ(cx, string);
        size_t l = JS_GetStringLength(string);
        char* pUTF8Str = cc_utf16_to_utf8((const unsigned short*)chars, l, NULL, NULL);
        buffer = pUTF8Str;
    }

    std::string get() {
        return buffer;
    }

    operator std::string() {
        return std::string(buffer);
    }
    operator char*() {
        return (char*)buffer;
    }
};


JSBool jsval_to_int32( JSContext *cx, jsval vp, int32_t *outval )
{
    JSBool ok = JS_TRUE;
    int32_t val;
    ok &= JS_ValueToInt32(cx, vp, &val);
    if (!ok) {
        LOGD("jsval_to_int32: the argument is not a number");
        return JS_FALSE;
    }

    *outval = val;

    return ok;
}

JSBool jsval_to_uint32( JSContext *cx, jsval vp, uint32_t *outval )
{
    JSBool ok = JS_TRUE;
	uint32_t val;
    ok &= JS_ValueToECMAUint32(cx, vp, &val);
    if (!ok) {
        LOGD("jsval_to_uint32: the argument is not a number");
        return JS_FALSE;
    }

    *outval = val;

    return ok;
}

JSBool jsval_to_uint16( JSContext *cx, jsval vp, uint16_t *outval )
{
    JSBool ok = JS_TRUE;
    uint16_t val;
    ok &= JS_ValueToUint16(cx, vp, &val);
    if (!ok) {
        LOGD("jsval_to_uint16: the argument is not a number");
        return JS_FALSE;
    }

    *outval = val;

    return ok;
}

JSBool jsval_to_long_long(JSContext *cx, jsval vp, long long* r) {
    JSBool ok = JS_TRUE;
	int64_t val;
    ok &= JS_ValueToInt64( cx, vp, &val );
    if (!ok) {
        LOGD("jsval_to_long_long: Error converting value to object");
        return JS_FALSE;
    }
    
    *r = (long long)val;
    return ok;
}

JSBool jsval_to_long(JSContext *cx, jsval vp, long* ret)
{
    JSBool ok = JS_TRUE;
	int32_t val;
    ok &= JS_ValueToInt32(cx, vp, &val);
    if (!ok) {
        LOGD("jsval_to_long: the argument is not a number");
        return JS_FALSE;
    }

    *ret = (long)val;

    return ok;
}

JSBool jsval_to_std_string(JSContext *cx, jsval v, std::string* ret) {
    JSString *tmp = JS_ValueToString(cx, v);
    if (!tmp) {
        LOGD("jsval_to_std_string: the jsval is not a string.");
        return JS_FALSE;
    }

    JSStringWrapper str(tmp, cx);
    *ret = str.get();
    return JS_TRUE;
}

JSBool jsval_to_TProductInfo(JSContext *cx, jsval v, TProductInfo* ret)
{
    JSObject* tmp = JSVAL_TO_OBJECT(v);
    if (!tmp) {
        LOGD("jsval_to_TProductInfo: the jsval is not an object.");
        return JS_FALSE;
    }

    JSObject* it = JS_NewPropertyIterator(cx, tmp);

    while (true)
    {
        jsid idp;
        jsval key;
        if (! JS_NextProperty(cx, it, &idp) || ! JS_IdToValue(cx, idp, &key))
            return JS_FALSE; // error
        if (key == JSVAL_VOID)
            break; // end of iteration
        if (! JSVAL_IS_STRING(key))
            continue; // ignore integer properties
        JS::RootedValue value(cx);
        JS_GetPropertyById(cx, tmp, idp, &value);
        if (! JSVAL_IS_STRING(value))
            continue; // ignore integer properties

        JSStringWrapper strWrapper(JSVAL_TO_STRING(key), cx);
        JSStringWrapper strWrapper2(JSVAL_TO_STRING(value), cx);

        (*ret)[strWrapper.get()] = strWrapper2.get();
        LOGD("iterate object: key = %s, value = %s", strWrapper.get().c_str(), strWrapper2.get().c_str());
    }

    return JS_TRUE;
}

JSBool jsval_to_TIAPDeveloperInfo(JSContext *cx, jsval v, TIAPDeveloperInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_TAdsDeveloperInfo(JSContext *cx, jsval v, TAdsDeveloperInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_TAdsInfo(JSContext *cx, jsval v, TAdsInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_TShareDeveloperInfo(JSContext *cx, jsval v, TShareDeveloperInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_TShareInfo(JSContext *cx, jsval v, TShareInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_TPaymentInfo(JSContext *cx, jsval v, std::map<std::string, std::string>* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_TSocialDeveloperInfo(JSContext *cx, jsval v, TSocialDeveloperInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_TAchievementInfo(JSContext *cx, jsval v, TAchievementInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_TUserDeveloperInfo(JSContext *cx, jsval v, TUserDeveloperInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

JSBool jsval_to_LogEventParamMap(JSContext *cx, jsval v, LogEventParamMap** ret)
{
    JSBool jsret = JS_FALSE;
    if (v.isObject())
    {
        LogEventParamMap* tmp = new LogEventParamMap();
        jsret = jsval_to_TProductInfo(cx, v, tmp);
        if (jsret) {
            *ret = tmp;
        }
    }

    return jsret;
}

JSBool jsval_to_StringMap(JSContext *cx, jsval v, StringMap* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}

// From native type to jsval
jsval int32_to_jsval( JSContext *cx, int32_t number )
{
    return INT_TO_JSVAL(number);
}

jsval uint32_to_jsval( JSContext *cx, uint32_t number )
{
    return UINT_TO_JSVAL(number);
}

jsval long_long_to_jsval(JSContext* cx, long long v) {
    JSObject *tmp = JS_NewUint32Array(cx, 2);
    uint32_t *data = (uint32_t *)JS_GetArrayBufferViewData(tmp);
    data[0] = ((uint32_t *)(&v))[0];
    data[1] = ((uint32_t *)(&v))[1];
    return OBJECT_TO_JSVAL(tmp);
}

jsval long_to_jsval(JSContext* cx, long v)
{
    return INT_TO_JSVAL(v);
}

jsval std_string_to_jsval(JSContext* cx, const std::string& v) {
    return c_string_to_jsval(cx, v.c_str());
}

jsval c_string_to_jsval(JSContext* cx, const char* v, size_t length /* = -1 */) {
    if (v == NULL) {
        return JSVAL_NULL;
    }
    jsval ret = JSVAL_NULL;
    int utf16_size = 0;
    jschar* strUTF16 = (jschar*)cc_utf8_to_utf16(v, length, &utf16_size);

    if (strUTF16 && utf16_size > 0) {
        JSString* str = JS_NewUCStringCopyN(cx, strUTF16, utf16_size);
        if (str) {
            ret = STRING_TO_JSVAL(str);
        }
        delete[] strUTF16;
    }
    return ret;
}

jsval TProductInfo_to_jsval(JSContext *cx, TProductInfo& ret)
{
    JSObject *tmp = JS_NewObject(cx, NULL, NULL, NULL);
    if (!tmp) return JSVAL_NULL;

    for (TProductInfo::iterator it = ret.begin(); it != ret.end(); ++it)
    {
        JS_DefineProperty(cx, tmp, it->first.c_str(), std_string_to_jsval(cx, it->second), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
    }

    return OBJECT_TO_JSVAL(tmp);
}

jsval LogEventParamMap_to_jsval(JSContext *cx, LogEventParamMap*& ret)
{// TODO:
    return JSVAL_NULL;
}

}// namespace pluginx {

