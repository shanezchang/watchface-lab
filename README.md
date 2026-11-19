# Watch Face Lab

<img src="Clocky/Assets.xcassets/AppIcon.appiconset/FaceLab-Plates.png" alt="Face Lab 应用图标" width="80">

Face Lab 是一款开源 watchOS 应用，用于浏览和全屏显示 Apple Watch 上的表盘。它通过 watchOS 的系统渲染器呈现设备内置的表盘样式，提供分类、预览和切换，并在手表上记住所选样式。

## 快速开始

需要一台装有 Xcode 和 watchOS SDK 的 Mac。使用模拟器时，在 Xcode 中安装对应的 watchOS 模拟器运行时。

```sh
git clone https://github.com/shanezchang/watchface-lab.git
cd watchface-lab
open FaceLab.xcodeproj
```

在 Xcode 中选择 `FaceLab` scheme，选中一个 Apple Watch 模拟器并运行。也可以在仓库根目录直接构建模拟器版本。

```sh
xcodebuild -project FaceLab.xcodeproj -scheme FaceLab -configuration Debug \
  -destination 'generic/platform=watchOS Simulator' \
  -derivedDataPath build/simulator CODE_SIGNING_ALLOWED=NO build
```

### 安装到 Apple Watch

1. 在 Xcode 中登录 Apple 账号。用 Device Hub 配对手表和伴侣 iPhone，并按提示启用开发者模式。 [设备配对](https://developer.apple.com/documentation/xcode/pairing-your-devices-with-your-mac) · [开发者模式](https://developer.apple.com/documentation/xcode/enabling-developer-mode-on-a-device)
2. 在 `FaceLab` target 的 **Signing & Capabilities** 中开启自动签名，选择自己的 Team，并设置该团队可用的 Bundle Identifier。
3. 选择配对后的 Apple Watch 作为运行目标，在 Xcode 中运行。安装完成后，可在手表的应用列表打开 **Face Lab**。

通过 Personal Team 安装的开发版本需要定期重新签名。更新现有安装时，沿用原 Team 和 Bundle Identifier。终端操作可按[真机安装流程](.agents/skills/watch-face-lab/SKILL.md#physical-apple-watch)执行。 [Apple 开发者账号说明](https://developer.apple.com/help/account/basics/about-your-developer-account/)

## 使用 Face Lab

1. 打开 Face Lab，长按当前表盘进入 **Categories**。
2. 选择分类并浏览预览，轻点要使用的表盘。
3. Face Lab 会在下次启动时尝试恢复该选择。首次启动时优先展示设备可用的黑底橙字 Hermès 款。

## 运行范围与兼容性

Face Lab 的浏览和显示都发生在应用内。Apple Watch 的系统表盘通过系统提供的表盘图库管理。 [Apple 表盘图库](https://support.apple.com/en-ie/guide/watch/apda6559ad78/watchos)

项目调用 `NanoTimeKit` 等 watchOS 私有系统框架。可选表盘取决于设备自带的资源，系统升级也可能改变私有接口的行为。真机构建应采用 Xcode 为目标设备列出的架构，例如 Series 7 使用 `arm64_32`。

## 项目结构

| 路径 | 用途 |
| --- | --- |
| [`Clocky/`](Clocky/) | watchOS 应用代码、表盘分类、设备端偏好与图标资源 |
| [`FaceLab.xcodeproj/`](FaceLab.xcodeproj/) | 独立 watchOS target 和共享 scheme |
| `*.xcframework/` | 构建所需的接口声明和链接存根，运行时实现由 watchOS 提供 |

## AI 助手

仓库根目录提供 [`AGENTS.md`](AGENTS.md)。配套的 [`watch-face-lab` Skill](.agents/skills/watch-face-lab/SKILL.md) 给出了模拟器运行、真机签名安装和故障排查步骤。可以把仓库链接和下面这样的任务交给你的 AI 助手。

> 读取仓库的 AGENTS.md 和 watch-face-lab Skill，在本机选一个可用的 Apple Watch 模拟器，构建并运行 Face Lab，然后说明运行结果。

## 贡献

欢迎通过 [Issues](https://github.com/shanezchang/watchface-lab/issues) 报告问题或提出功能建议。遇到构建或显示问题时，请附上仓库版本、Xcode 与 watchOS 版本、机型或模拟器、复现步骤和相关错误。提交 [Pull Request](https://github.com/shanezchang/watchface-lab/pulls) 时，请说明变更影响了哪段使用流程及如何检查。

## 许可与致谢

Face Lab 派生自 Jinwoo Kim（`pookjw`）的 Clocky 1.1.2，基于提交 `88be58720bd0c60f64a6e8265c933b4a0c39d2bb`。Clocky 将应用内表盘方案的创意归功于 `mightywhite`。 [上游项目与原始署名](https://github.com/pookjw/Clocky/blob/88be58720bd0c60f64a6e8265c933b4a0c39d2bb/README.md)

项目沿用 GNU General Public License v3.0。Apple Watch 和相关表盘标识归各权利人所有。 [LICENSE](LICENSE)
