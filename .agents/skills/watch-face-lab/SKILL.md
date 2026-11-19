---
name: watch-face-lab
description: Build, run, sign, install, and troubleshoot Face Lab from its watchOS source repository. Use for simulator smoke checks, Apple Watch installation, or Face Lab build and launch issues.
---

# Build and run Face Lab

Run commands from the checkout that contains `FaceLab.xcodeproj`. The shared scheme is `FaceLab` and both build paths produce `FaceLab.app`. [Watch Face Lab repository](https://github.com/shanezchang/watchface-lab)

## Prepare the toolchain

```sh
xcode-select -p
xcodebuild -version
xcodebuild -project FaceLab.xcodeproj -list
```

Use a full Xcode installation with the watchOS SDK. Use Xcode's platform components settings to locate a missing SDK or simulator runtime. Choose the build and run path that matches the requested outcome.

## Simulator

Build without device signing.

```sh
xcodebuild -project FaceLab.xcodeproj -scheme FaceLab -configuration Debug \
  -destination 'generic/platform=watchOS Simulator' \
  -derivedDataPath build/simulator CODE_SIGNING_ALLOWED=NO build
```

To run the app, use `xcrun simctl list devices available` to choose an Apple Watch simulator. The `-b` flag starts the selected simulator if needed and waits for it to finish booting.

```sh
face_lab_sim_id='YOUR_WATCH_SIMULATOR_ID'
face_lab_app='build/simulator/Build/Products/Debug-watchsimulator/FaceLab.app'
face_lab_bundle=$(/usr/libexec/PlistBuddy -c 'Print :CFBundleIdentifier' "$face_lab_app/Info.plist")

xcrun simctl bootstatus "$face_lab_sim_id" -b
xcrun simctl install "$face_lab_sim_id" "$face_lab_app"
xcrun simctl launch "$face_lab_sim_id" "$face_lab_bundle"
```

For a UI check, wait for the face to render, long-press to open Categories, pick a face, and relaunch to check the saved selection. Capture the app screen with `xcrun simctl io "$face_lab_sim_id" screenshot /path/to/screenshot.png` when useful.

## Physical Apple Watch

1. Confirm the intended watch, Xcode signing team, and bundle identifier. For an update, use the original team and bundle identifier so the app keeps its local selection.
2. Confirm the watch is paired, unlocked, and available to Xcode. Follow Apple’s Device Hub and Developer Mode setup when needed. [Device Hub](https://developer.apple.com/documentation/xcode/pairing-your-devices-with-your-mac) · [Developer Mode](https://developer.apple.com/documentation/xcode/enabling-developer-mode-on-a-device)
3. Read the Xcode destination `id` and `arch` for that watch. Read the CoreDevice `Identifier` for the same physical watch. Use the two identifiers for their respective commands.

```sh
xcodebuild -project FaceLab.xcodeproj -scheme FaceLab -showdestinations
xcrun devicectl list devices
```

Replace the five values below with the selected team's and watch's values. The architecture example is for a Series 7.

```sh
face_lab_team='YOUR_TEAM_ID'
face_lab_bundle='org.example.watchfacelab'
face_lab_watch_udid='YOUR_XCODE_WATCH_ID'
face_lab_core_id='YOUR_COREDEVICE_IDENTIFIER'
face_lab_arch='arm64_32'

xcodebuild -project FaceLab.xcodeproj -scheme FaceLab -configuration Debug \
  -destination "platform=watchOS,arch=$face_lab_arch,id=$face_lab_watch_udid" \
  -destination-timeout 45 -derivedDataPath build/watch -allowProvisioningUpdates \
  "DEVELOPMENT_TEAM=$face_lab_team" "PRODUCT_BUNDLE_IDENTIFIER=$face_lab_bundle" \
  "ARCHS=$face_lab_arch" EXCLUDED_ARCHS= ONLY_ACTIVE_ARCH=NO build
```

Check the signed product and its architecture before installing. Inspect the embedded profile locally with `security cms -D -i` if provisioning is in question. Look for the matching team, an unexpired profile, and the selected watch in `ProvisionedDevices`.

For an unregistered watch, register the selected device in Xcode or add `-allowProvisioningDeviceRegistration` alongside `-allowProvisioningUpdates` when registration is part of the task.

```sh
face_lab_app='build/watch/Build/Products/Debug-watchos/FaceLab.app'
codesign --verify --deep --strict "$face_lab_app"
xcrun lipo -archs "$face_lab_app/FaceLab"
```

After the build and signature checks pass, install and launch on the selected watch.

```sh
xcrun devicectl device install app --device "$face_lab_core_id" "$face_lab_app"
xcrun devicectl device process launch --device "$face_lab_core_id" "$face_lab_bundle"
```

## Diagnose failures

| Symptom | Check |
| --- | --- |
| Watch missing or stuck on Connecting | Check pairing, Developer Mode, unlock status, and availability in Device Hub. Use `xcrun devicectl device info lockState --device "$face_lab_core_id"` to check reachability. |
| Ineligible architecture | Match the physical destination's architecture to both the build arguments and the target's `ARCHS[sdk=watchos*]` setting. Check the built slice with `lipo`. |
| Provisioning or install failure | Check the team, bundle identifier, profile expiry, and watch registration. Xcode can register the intended watch for a team when needed. Renew an expired Personal Team install with the same signing identity and bundle identifier. |
| App launched but face is missing | Check available categories and the installed watchOS build. The viewer relies on the device's local face resources and private rendering interfaces. Confirm the displayed app after startup on an awake watch. |

## Report the result

Record the source revision and the target model or simulator and OS. Report which phases succeeded when applicable, including build, install, launch, and visible rendering. Verify the UI by observing the app in the simulator, capturing the foreground app with `devicectl device capture screenshot`, or having the device owner confirm it. Redact personal device identifiers and signing profile contents from shared output.
