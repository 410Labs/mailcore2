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
                      url: "https://github.com/410labs/mailcore2/raw/master/bin/MailCore2-2023-10-18.xcframework.zip",
                      checksum: "ab0451cf0761c5286d2c2c0cc4417e1303eb2c7b0fb5d3f842c52dec336921c9")
    ]
)
