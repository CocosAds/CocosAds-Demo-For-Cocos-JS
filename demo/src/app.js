
var HelloWorldLayer = cc.Layer.extend({
    ctor:function () {

        this._super();

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

