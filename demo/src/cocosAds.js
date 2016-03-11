/**
 * Created by Jacky on 16/3/2.
 */

var cc = cc || {};

cc.CocosAds = cc.CocosAds || {};

//Callback code
cc.CocosAds.CocosAdsResultCode = {
    kAdsReceiveSuccess: 0,
    kAdsReceiveFailed: 1,
    kAdsPresentScreen: 2,
    kAdsDismissScreen: 3
};

//Interstitial close mode
cc.CocosAds.CLOSE_MODE_CLOSE = 0;
cc.CocosAds.CLOSE_MODE_COUNTDOWN = 1;
cc.CocosAds.CLOSE_MODE_COUNTDOWN_WITH_CLOSE = 2;


var _bannerListener;
var _jsbAddBannerAdListener = cc.CocosAds.prototype.addBannerAdListener;
cc.CocosAds.prototype.addBannerAdListener = function ( bannerListener ){
    _bannerListener = bannerListener;
    _jsbAddBannerAdListener.call(this, _bannerListener);
};

var _jsbRemoveBannerAdListener = cc.CocosAds.prototype.removeBannerAdListener;
cc.CocosAds.prototype.removeBannerAdListener = function () {
    _jsbRemoveBannerAdListener.call(this);
    _bannerListener = null;
};

var _interstitialListener;
var _jsbAddInterstitialAdListener = cc.CocosAds.prototype.addInterstitialAdListener;
cc.CocosAds.prototype.addInterstitialAdListener = function ( interstitialListener) {
    _interstitialListener = interstitialListener;
    _jsbAddInterstitialAdListener.call(this, _interstitialListener);
};

var _jsbRemoveInterstitialAdListener = cc.CocosAds.prototype.removeInterstitialAdListener;
cc.CocosAds.prototype.removeInterstitialAdListener = function () {
    _jsbRemoveInterstitialAdListener.call(this);
    _interstitialListener = null;
};