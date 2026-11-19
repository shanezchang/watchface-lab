# Face Lab

Face Lab is a standalone watchOS app that presents system watch faces inside its own UI. See the [README](README.md) for the user flow and [watch-face-lab Skill](.agents/skills/watch-face-lab/SKILL.md) for the build, run, install, and diagnosis workflow.

## Working in this repository

- Use the shared `FaceLab` scheme in `FaceLab.xcodeproj`. The app target is watch-only and the resulting product is `FaceLab.app`.
- App code and assets are in `Clocky/`. The Objective-C and Objective-C++ sources use manual retain and release. Follow the surrounding ownership conventions when editing them.
- The workspace includes text headers and linker stubs for system frameworks. Preserve the device and simulator slices when adjusting an interface.
- Configure personal signing through Xcode or build arguments. Keep certificates, provisioning profiles, device identifiers, and personal team IDs out of tracked files and public logs.

## Checking changes

- Use the simulator build in the skill as a compile check for code changes. For viewer or selection changes, also exercise launch, long-press, choosing a face, and restoring the choice on relaunch.
- For icon changes, check the `AppIcon` asset entry and confirm the rendition is in the built app.
- For physical installs, use the watch and signing team intended for the current task. Confirm each result independently when applicable, including build, install, launch, and visible UI.
- Use repo and platform settings as the basis for compatibility documentation. Record environment-specific validation in the change report.
