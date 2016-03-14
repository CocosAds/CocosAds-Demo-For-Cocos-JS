rm -rf sdk
mkdir sdk
mkdir sdk/Classes
classPath="demo/frameworks/runtime-src/Classes/"
cp ${classPath}"CocosAds.h" ${classPath}"CocosAds-android.cpp" ${classPath}"CocosAds-ios.mm" ${classPath}"jsb_cocos2dx_cocosAds.hpp" ${classPath}"jsb_cocos2dx_cocosAds.cpp" sdk/Classes/

helperPath="demo/frameworks/runtime-src/proj.android/src/com/"
mkdir sdk/com
cp -rf ${helperPath} sdk/com
