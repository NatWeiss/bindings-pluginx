#include "jsb_pluginx_extension_registration.h"
#include "jsb_pluginx_manual_callback.h"
#include "jsb_pluginx_manual_protocols.h"

static jsval anonEvaluate(JSContext *cx, JSObject *thisObj, const char* string) {
    jsval out;
    if (JS_EvaluateScript(cx, thisObj, string, strlen(string), "(string)", 1, &out) == JS_TRUE) {
        return out;
    }
    return JSVAL_VOID;
}

extern JSObject *jsb_cocos2d_plugin_ProtocolIAP_prototype;
extern JSObject *jsb_cocos2d_plugin_ProtocolAds_prototype;
extern JSObject *jsb_cocos2d_plugin_ProtocolShare_prototype;
extern JSObject *jsb_cocos2d_plugin_PluginProtocol_prototype;
extern JSObject *jsb_cocos2d_plugin_ProtocolSocial_prototype;
extern JSObject *jsb_cocos2d_plugin_ProtocolUser_prototype;

void register_pluginx_js_extensions(JSContext* cx, JSObject* obj)
{
	// first, try to get the ns
	JS::RootedValue nsval(cx);
	JS::RootedObject ns(cx);
	JS_GetProperty(cx, obj, "plugin", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "plugin", nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

/*
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JSObject *ns;
    JS_GetProperty(cx, obj, "plugin", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "plugin", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
*/

    JS_DefineFunction(cx, jsb_cocos2d_plugin_ProtocolIAP_prototype, "setResultListener", js_pluginx_ProtocolIAP_setResultListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_ProtocolAds_prototype, "setAdsListener", js_pluginx_ProtocolAds_setAdsListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_ProtocolShare_prototype, "setResultListener", js_pluginx_ProtocolShare_setResultListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_ProtocolSocial_prototype, "setListener", js_pluginx_ProtocolSocial_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_ProtocolUser_prototype, "setActionListener", js_pluginx_ProtocolUser_setActionListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_PluginProtocol_prototype, "callFuncWithParam", js_pluginx_PluginProtocol_callFuncWithParam, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_PluginProtocol_prototype, "callStringFuncWithParam", js_pluginx_PluginProtocol_callStringFuncWithParam, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_PluginProtocol_prototype, "callIntFuncWithParam", js_pluginx_PluginProtocol_callIntFuncWithParam, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_PluginProtocol_prototype, "callFloatFuncWithParam", js_pluginx_PluginProtocol_callFloatFuncWithParam, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, jsb_cocos2d_plugin_PluginProtocol_prototype, "callBoolFuncWithParam", js_pluginx_PluginProtocol_callBoolFuncWithParam, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    obj = ns;
    js_register_pluginx_protocols_PluginParam(cx, obj);
}
