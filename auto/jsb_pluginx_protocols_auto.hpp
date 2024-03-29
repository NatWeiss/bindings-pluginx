#ifndef __pluginx_protocols_h__
#define __pluginx_protocols_h__

#include "jsapi.h"
#include "jsfriendapi.h"

#ifndef JSBool
#define JSBool bool
#define JS_TRUE (bool)1
#define JS_FALSE (bool)0
#endif

extern JSClass  *jsb_cocos2d_plugin_PluginProtocol_class;
extern JSObject *jsb_cocos2d_plugin_PluginProtocol_prototype;

JSBool js_pluginx_protocols_PluginProtocol_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_protocols_PluginProtocol_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_PluginProtocol(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_pluginx_protocols_PluginProtocol_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_PluginProtocol_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_PluginProtocol_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_PluginProtocol_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_plugin_PluginManager_class;
extern JSObject *jsb_cocos2d_plugin_PluginManager_prototype;

JSBool js_pluginx_protocols_PluginManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_protocols_PluginManager_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_PluginManager(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_pluginx_protocols_PluginManager_unloadPlugin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_PluginManager_loadPlugin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_PluginManager_end(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_PluginManager_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_plugin_ProtocolAnalytics_class;
extern JSObject *jsb_cocos2d_plugin_ProtocolAnalytics_prototype;

JSBool js_pluginx_protocols_ProtocolAnalytics_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_protocols_ProtocolAnalytics_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_ProtocolAnalytics(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_pluginx_protocols_ProtocolAnalytics_logTimedEventBegin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAnalytics_logError(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAnalytics_setCaptureUncaughtException(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAnalytics_setSessionContinueMillis(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAnalytics_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAnalytics_logTimedEventEnd(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_plugin_ProtocolIAP_class;
extern JSObject *jsb_cocos2d_plugin_ProtocolIAP_prototype;

JSBool js_pluginx_protocols_ProtocolIAP_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_protocols_ProtocolIAP_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_ProtocolIAP(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_pluginx_protocols_ProtocolIAP_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolIAP_onPayResult(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolIAP_configDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_plugin_ProtocolAds_class;
extern JSObject *jsb_cocos2d_plugin_ProtocolAds_prototype;

JSBool js_pluginx_protocols_ProtocolAds_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_protocols_ProtocolAds_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_ProtocolAds(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_pluginx_protocols_ProtocolAds_showAds(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAds_hideAds(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAds_queryPoints(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAds_spendPoints(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAds_configDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAds_getAdsListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolAds_setAdsListener(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_plugin_ProtocolShare_class;
extern JSObject *jsb_cocos2d_plugin_ProtocolShare_prototype;

JSBool js_pluginx_protocols_ProtocolShare_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_protocols_ProtocolShare_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_ProtocolShare(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_pluginx_protocols_ProtocolShare_onShareResult(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolShare_share(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolShare_configDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_plugin_ProtocolSocial_class;
extern JSObject *jsb_cocos2d_plugin_ProtocolSocial_prototype;

JSBool js_pluginx_protocols_ProtocolSocial_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_protocols_ProtocolSocial_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_ProtocolSocial(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_pluginx_protocols_ProtocolSocial_showLeaderboard(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolSocial_showAchievements(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolSocial_submitScore(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolSocial_configDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolSocial_unlockAchievement(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_plugin_ProtocolUser_class;
extern JSObject *jsb_cocos2d_plugin_ProtocolUser_prototype;

JSBool js_pluginx_protocols_ProtocolUser_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_protocols_ProtocolUser_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_ProtocolUser(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_pluginx_protocols_ProtocolUser_isLogined(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolUser_logout(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolUser_configDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolUser_login(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_protocols_ProtocolUser_getSessionID(JSContext *cx, uint32_t argc, jsval *vp);
#endif

