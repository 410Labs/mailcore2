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
                      url: "https://github.com/410labs/mailcore2/raw/master/bin/MailCore2-2023-10-25.xcframework.zip",
                      checksum: "d91f01425c75b4dc259a8d40982afecda10ae9a8595e38470debb415a5c7bb63")
    ]
)
