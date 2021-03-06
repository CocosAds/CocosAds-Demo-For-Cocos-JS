#include "base/ccConfig.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#ifndef __cocos2dx_cocosAds_h__
#define __cocos2dx_cocosAds_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_CocosAds_class;
extern JSObject *jsb_CocosAds_prototype;

//auto-binding
bool js_cocos2dx_cocosAds_CocosAds_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_cocosAds_CocosAds_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_cocosAds_CocosAds(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_cocosAds(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_cocosAds_CocosAds_showBanner(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_removeInterstitialAdListener(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_showInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_hideBanner(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_setInterstitialCloseMode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_setInterstitialDisplayTime(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_hideInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_removeBannerAdListener(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

//manual-binding
bool js_cocos2dx_cocosAds_CocosAds_addBannerAdListener(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_cocosAds_CocosAds_addInterstitialAdListener(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __cocos2dx_cocosAds_h__
#endif //#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
