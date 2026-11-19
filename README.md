# Watch Face Lab

Face Lab 是一个 watchOS 表盘显示实验。打开应用会全屏显示手表已有的表盘，默认是黑底橙字的 Hermès 款，长按可选其他款。选择保存在应用自己的偏好中。

表盘由 watchOS 的 `NanoTimeKit` 等私有系统框架实时绘制，显示范围是 Face Lab 的前台界面。应用通过 Xcode 的常规开发签名安装，渲染兼容性取决于 watchOS 版本和手表上的表盘资源。

Apple 的系统表盘支持在已有模板上定制、共享和加入 WidgetKit 复杂功能。原生 Hermès 表盘的可用性由 Apple 按设备决定。 [定制系统表盘](https://support.apple.com/en-ie/guide/watch/apda6559ad78/watchos) · [添加共享表盘](https://developer.apple.com/documentation/clockkit/clkwatchfacelibrary/addwatchface%28at%3Acompletionhandler%3A%29)

## 从源码运行

使用带 watchOS SDK 的 Xcode。打开 `FaceLab.xcodeproj`，选择 `FaceLab` scheme 和 Apple Watch 模拟器，然后运行。也可以先检查命令行构建。

```sh
xcodebuild -project FaceLab.xcodeproj -scheme FaceLab -configuration Debug \
  -destination 'generic/platform=watchOS Simulator' \
  -derivedDataPath build/simulator CODE_SIGNING_ALLOWED=NO build
```

## 在 Series 7 上安装

1. 在 Xcode 中登录自己的 Apple 账号。在 Device Hub 确认手表已配对、解锁并启用开发者模式。 [Apple 的设备配对说明](https://developer.apple.com/documentation/xcode/pairing-your-devices-with-your-mac)
2. 用 `xcodebuild -project FaceLab.xcodeproj -scheme FaceLab -showdestinations` 找到手表的 Xcode `id`。用 `xcrun devicectl list devices` 找到同一块表的 CoreDevice `Identifier`。
3. 把下面的四个占位值替换为你自己的值。`team` 是 Xcode 签名团队 ID，`bundle` 是该团队下的独立包名。Series 7 的构建用 `arm64_32`。

```sh
team='YOUR_TEAM_ID'
bundle='org.example.watchfacelab'
watch_udid='YOUR_XCODE_WATCH_ID'
watch_id='YOUR_COREDEVICE_IDENTIFIER'

xcodebuild -project FaceLab.xcodeproj -scheme FaceLab -configuration Debug \
  -destination "platform=watchOS,arch=arm64_32,id=$watch_udid" \
  -destination-timeout 45 -derivedDataPath build/watch \
  -allowProvisioningUpdates "DEVELOPMENT_TEAM=$team" \
  "PRODUCT_BUNDLE_IDENTIFIER=$bundle" ARCHS=arm64_32 EXCLUDED_ARCHS= \
  ONLY_ACTIVE_ARCH=NO build

app='build/watch/Build/Products/Debug-watchos/FaceLab.app'
codesign --verify --deep --strict "$app"
xcrun lipo -archs "$app/FaceLab"
xcrun devicectl device install app --device "$watch_id" "$app"
xcrun devicectl device process launch --device "$watch_id" "$bundle"
```

安装后可以直接在表上按表冠打开 **Face Lab**。开发描述文件的期限以 `.app` 中的 `embedded.mobileprovision` 为准。到期后，用相同团队和包名重签安装。

## 已验证环境

- Xcode 27.2，Series 7 模拟器，watchOS 26.5。首次启动显示黑底橙字款，UI 测试通过长按、进入 Hermès 分类及选择表盘。
- Xcode 27.2，Series 7 真机目标，watchOS 26.6。Face Lab 通过 `arm64_32` 构建、签名和描述文件校验。此前的 Clocky 原型在这台真机完成了安装、启动和显示验证。

## 源码与许可

- 渲染和切换逻辑来自 Jinwoo Kim（`pookjw`）的 Clocky 1.1.2，固定在 `88be58720bd0c60f64a6e8265c933b4a0c39d2bb`。上游 README 将创意归功于 `mightywhite` 提交给 HermesEnabler 的 PR #93。Face Lab 的构建输入是 Clocky 的手表端源码、接口声明与 Xcode SDK。 [Clocky 上游 README](https://github.com/pookjw/Clocky/blob/88be58720bd0c60f64a6e8265c933b4a0c39d2bb/README.md)
- 2026-11-19 将工程整理为独立的 watchOS 应用，补充 Series 7 架构，设置应用内默认款，移除启动时主动请求运动数据的逻辑。五个 `.xcframework` 目录存放文本头文件和链接存根，运行时使用设备上的 Apple 框架。表盘图形直接由系统显示。
- 本仓库沿用上游的 [GNU GPL v3](LICENSE)。表盘和框架中的第三方品牌及素材归各权利人所有。
