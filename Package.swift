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
                      url: "https://github.com/410labs/mailcore2/raw/master/bin/MailCore2-2023-10-26.xcframework.zip",
                      checksum: "50f5f0c15454d5065b40613164df7258d0ca07d94932a0ae93a1f86849cde1e5")
    ]
)
