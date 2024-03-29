#ifndef __JS_MANUAL_CALLBACK_H__
#define __JS_MANUAL_CALLBACK_H__

#include "jsapi.h"
#include "jsfriendapi.h"

#ifndef JSBool
#define JSBool bool
#define JS_TRUE (bool)1
#define JS_FALSE (bool)0
#endif

JSBool js_pluginx_ProtocolIAP_setResultListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAds_setAdsListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolShare_setResultListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolSocial_setListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolUser_setActionListener(JSContext *cx, uint32_t argc, jsval *vp);

#endif /* __JS_MANUAL_CALLBACK_H__ */
