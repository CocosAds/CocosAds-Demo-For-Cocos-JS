
var HelloWorldLayer = cc.Layer.extend({
    ctor:function () {

        this._super();

        if(cc.sys.os == cc.sys.OS_ANDROID || cc.sys.os == cc.sys.OS_IOS) {
            // 初始化 CocosAds SDK
            var publisherID = "";
            if(cc.sys.os == cc.sys.OS_ANDROID) {
                publisherID = "855310162-C1F5CC-48E8-2B19-34FCDC917";
            }else if(cc.sys.os == cc.sys.OS_IOS) {
                publisherID = "855595180-47D2E7-2298-EAA9-6E1886A1F";
            }
            cc.CocosAds.getInstance().init(publisherID);
        }

        var size = cc.winSize;

        var labelItemBanner = new cc.MenuItemFont("Banner 广告", function (sender) {
            cc.director.runScene(new BannerScene());
        }, this);
        labelItemBanner.setPosition(cc.p(size.width/2, size.height - 50));

        var labelItemInterstitial = new cc.MenuItemFont("插屏广告", function (sender) {
            cc.director.runScene(new InterstitialScene());
        }, this);
        labelItemInterstitial.setPosition(cc.p(size.width/2, size.height - 100));

        var menu = new cc.Menu(labelItemBanner, labelItemInterstitial);
        menu.setPosition(cc.p(0,0));
        this.addChild(menu);

        return true;
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

