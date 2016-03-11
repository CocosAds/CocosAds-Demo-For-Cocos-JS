/**
 * Created by Jacky on 16/3/2.
 */

var InterstitialLayer = cc.Layer.extend({
    ctor:function () {

        this._super();

        var size = cc.winSize;

        var labelBack = new cc.MenuItemFont("返回", function (sender) {

            if(cc.sys.os == cc.sys.OS_ANDROID || cc.sys.os == cc.sys.OS_IOS) {
                //移除广告监听(可选)
                cc.CocosAds.getInstance().removeInterstitialAdListener();
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
            cc.CocosAds.getInstance().setInterstitialCloseMode(cc.CocosAds.CLOSE_MODE_COUNTDOWN_WITH_CLOSE);

            cc.CocosAds.getInstance().setInterstitialDisplayTime(7);

            cc.CocosAds.getInstance().addInterstitialAdListener(function (code, result) {
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

            //展示广告（必选）
            var placementID = "";
            if (cc.sys.os == cc.sys.OS_ANDROID) {
                placementID = "855310162o2l2xm";
            } else if (cc.sys.os == cc.sys.OS_IOS) {
                placementID = "855595180o2lox4";
            }
            cc.CocosAds.getInstance().showInterstitial(placementID);
        }

        return true;
    }
});

var InterstitialScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new InterstitialLayer();
        this.addChild(layer);
    }
});