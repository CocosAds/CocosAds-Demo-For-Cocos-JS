/**
 * Created by Jacky on 16/3/2.
 */

var BannerLayer = cc.Layer.extend({
    ctor:function () {

        this._super();

        var size = cc.winSize;

        var labelBack = new cc.MenuItemFont("返回", function (sender) {

            if(cc.sys.os == cc.sys.OS_ANDROID || cc.sys.os == cc.sys.OS_IOS) {
                //移除广告监听(可选)
                cc.CocosAds.getInstance().removeBannerAdListener();
                //隐藏广告(可选)
                cc.CocosAds.getInstance().hideBanner();
            }

            cc.director.runScene(new HelloWorldScene());
        }, this);
        labelBack.setPosition(cc.p(labelBack.getContentSize().width/2, size.height - labelBack.getContentSize().height/2));

        var menu = new cc.Menu(labelBack);
        menu.setPosition(cc.p(0,0));
        this.addChild(menu);

        this.sprite = new cc.Sprite(res.HelloWorld_png);
        this.sprite.attr({
            x: size.width / 2,
            y: size.height / 2
        });
        this.addChild(this.sprite, 0);

        if(cc.sys.os == cc.sys.OS_ANDROID || cc.sys.os == cc.sys.OS_IOS) {
            //添加广告监听(可选)
            cc.CocosAds.getInstance().addBannerAdListener(function (code, result) {
                switch (code) {
                    case cc.CocosAds.CocosAdsResultCode.kAdsReceiveSuccess:
                        cc.log("CocosAdsDemo: " + result);
                        break;
                    case cc.CocosAds.CocosAdsResultCode.kAdsReceiveFailed:
                        cc.log("CocosAdsDemo: " + result);
                        break;
                    case cc.CocosAds.CocosAdsResultCode.kAdsPresentScreen:
                        cc.log("CocosAdsDemo: " + result);
                        break;
                    case cc.CocosAds.CocosAdsResultCode.kAdsDismissScreen:
                        cc.log("CocosAdsDemo: " + result);
                        break;
                    default:
                        break;
                }
            });

            //展示广告(必选)
            var placementID = "";
            if (cc.sys.os == cc.sys.OS_ANDROID) {
                placementID = "855310162o2l2x4";
            } else if (cc.sys.os == cc.sys.OS_IOS) {
                placementID = "855595180o2lowu";
            }
            cc.CocosAds.getInstance().showBanner(placementID);
        }

        return true;
    }
});

var BannerScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new BannerLayer();
        this.addChild(layer);
    }
});