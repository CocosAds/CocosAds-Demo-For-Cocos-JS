#include "jsb_cocos2dx_cocosAds.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "cocos2d_specifics.hpp"
#include "CocosAds.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    JS::RootedObject global(cx, ScriptingCore::getInstance()->getGlobalObject());
    isNewValid = JS_GetProperty(cx, global, "initializing", &initializing) && initializing.toBoolean();
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    JS_ReportError(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;    
}
JSClass  *jsb_CocosAds_class;
JSObject *jsb_CocosAds_prototype;

bool js_cocos2dx_cocosAds_CocosAds_showBanner(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_showBanner : Invalid Native Object");
    if (argc == 0) {
        cobj->showBanner();
        args.rval().setUndefined();
        return true;
    }
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_cocosAds_CocosAds_showBanner : Error processing arguments");
        cobj->showBanner(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_showBanner : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_removeInterstitialAdListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_removeInterstitialAdListener : Invalid Native Object");
    if (argc == 0) {
        cobj->removeInterstitialAdListener();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_removeInterstitialAdListener : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_showInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_showInterstitial : Invalid Native Object");
    if (argc == 0) {
        cobj->showInterstitial();
        args.rval().setUndefined();
        return true;
    }
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_cocosAds_CocosAds_showInterstitial : Error processing arguments");
        cobj->showInterstitial(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_showInterstitial : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_hideBanner(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_hideBanner : Invalid Native Object");
    if (argc == 0) {
        cobj->hideBanner();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_hideBanner : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_init : Invalid Native Object");
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_cocosAds_CocosAds_init : Error processing arguments");
        cobj->init(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_init : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_setInterstitialCloseMode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_setInterstitialCloseMode : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_cocosAds_CocosAds_setInterstitialCloseMode : Error processing arguments");
        cobj->setInterstitialCloseMode(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_setInterstitialCloseMode : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_setInterstitialDisplayTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_setInterstitialDisplayTime : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_cocosAds_CocosAds_setInterstitialDisplayTime : Error processing arguments");
        cobj->setInterstitialDisplayTime(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_setInterstitialDisplayTime : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_hideInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_hideInterstitial : Invalid Native Object");
    if (argc == 0) {
        cobj->hideInterstitial();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_hideInterstitial : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_removeBannerAdListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_removeBannerAdListener : Invalid Native Object");
    if (argc == 0) {
        cobj->removeBannerAdListener();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_removeBannerAdListener : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_cocosAds_CocosAds_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        CocosAds* ret = CocosAds::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<CocosAds>(cx, (CocosAds*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_getInstance : wrong number of arguments");
    return false;
}


void js_CocosAds_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CocosAds)", obj);
}

//manual-binding
bool js_cocos2dx_cocosAds_CocosAds_addBannerAdListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_addBannerAdListener : Invalid Native Object");
    if (argc == 1) {
        std::function<void (int, std::basic_string<char>)> arg0;
        do {
            if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
            {
                std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
                auto lambda = [=](int larg0, std::basic_string<char> larg1) -> void {
                    cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
                        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
                        jsval largv[2];
                        largv[0] = int32_to_jsval(cx, larg0);
                        largv[1] = std_string_to_jsval(cx, larg1);
                        JS::RootedValue rval(cx);
                        bool succeed = func->invoke(2, &largv[0], &rval);
                        if (!succeed && JS_IsExceptionPending(cx)) {
                            JS_ReportPendingException(cx);
                        }
                    });
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(0)
            ;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_cocosAds_CocosAds_addBannerAdListener : Error processing arguments");
        cobj->addBannerAdListener(arg0);
        args.rval().setUndefined();
        return true;
    }
    
    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_addBannerAdListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

bool js_cocos2dx_cocosAds_CocosAds_addInterstitialAdListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    CocosAds* cobj = (CocosAds *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_cocosAds_CocosAds_addInterstitialAdListener : Invalid Native Object");
    if (argc == 1) {
        std::function<void (int, std::basic_string<char>)> arg0;
        do {
            if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
            {
                std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
                auto lambda = [=](int larg0, std::basic_string<char> larg1) -> void
                {
                    cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
                        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
                        jsval largv[2];
                        largv[0] = int32_to_jsval(cx, larg0);
                        largv[1] = std_string_to_jsval(cx, larg1);
                        JS::RootedValue rval(cx);
                        bool succeed = func->invoke(2, &largv[0], &rval);
                        if (!succeed && JS_IsExceptionPending(cx)) {
                            JS_ReportPendingException(cx);
                        }
                    });
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(0)
            ;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_cocosAds_CocosAds_addInterstitialAdListener : Error processing arguments");
        cobj->addInterstitialAdListener(arg0);
        args.rval().setUndefined();
        return true;
    }
    
    JS_ReportError(cx, "js_cocos2dx_cocosAds_CocosAds_addInterstitialAdListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

void js_register_cocos2dx_cocosAds_CocosAds(JSContext *cx, JS::HandleObject global) {
    jsb_CocosAds_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_CocosAds_class->name = "CocosAds";
    jsb_CocosAds_class->addProperty = JS_PropertyStub;
    jsb_CocosAds_class->delProperty = JS_DeletePropertyStub;
    jsb_CocosAds_class->getProperty = JS_PropertyStub;
    jsb_CocosAds_class->setProperty = JS_StrictPropertyStub;
    jsb_CocosAds_class->enumerate = JS_EnumerateStub;
    jsb_CocosAds_class->resolve = JS_ResolveStub;
    jsb_CocosAds_class->convert = JS_ConvertStub;
    jsb_CocosAds_class->finalize = js_CocosAds_finalize;
    jsb_CocosAds_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("showBanner", js_cocos2dx_cocosAds_CocosAds_showBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeInterstitialAdListener", js_cocos2dx_cocosAds_CocosAds_removeInterstitialAdListener, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showInterstitial", js_cocos2dx_cocosAds_CocosAds_showInterstitial, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hideBanner", js_cocos2dx_cocosAds_CocosAds_hideBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_cocos2dx_cocosAds_CocosAds_init, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterstitialCloseMode", js_cocos2dx_cocosAds_CocosAds_setInterstitialCloseMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterstitialDisplayTime", js_cocos2dx_cocosAds_CocosAds_setInterstitialDisplayTime, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hideInterstitial", js_cocos2dx_cocosAds_CocosAds_hideInterstitial, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeBannerAdListener", js_cocos2dx_cocosAds_CocosAds_removeBannerAdListener, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        //manual-binding
        JS_FN("addBannerAdListener", js_cocos2dx_cocosAds_CocosAds_addBannerAdListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addInterstitialAdListener", js_cocos2dx_cocosAds_CocosAds_addInterstitialAdListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_cocos2dx_cocosAds_CocosAds_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_CocosAds_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_CocosAds_class,
        dummy_constructor<CocosAds>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "CocosAds", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<CocosAds> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_CocosAds_class;
        p->proto = jsb_CocosAds_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

void register_all_cocos2dx_cocosAds(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "cc", &ns);

    js_register_cocos2dx_cocosAds_CocosAds(cx, ns);
}

#endif //#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
