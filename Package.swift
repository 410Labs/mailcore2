// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MailCore2",
    platforms: [
        .iOS(.v12), .macOS(.v11)
    ],
    products: [
        .library(
            name: "MailCore2",
            targets: ["MailCore2"]),
    ],
    targets: [
        .binaryTarget(name: "MailCore2",
                      url: "https://github.com/410labs/mailcore2/raw/master/bin/MailCore2-2023-10-20.xcframework.zip",
                      checksum: "0f1e1770255ed4179023f080be29518a8ef02c2158af1fa9972277340a24723d")
    ]
)
