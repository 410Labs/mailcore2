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
                      checksum: "ba2e738c01471e727a172feb154651762bf9daa3414d0f968bc419ece19053ce")
    ]
)
