[![Apache
License](https://img.shields.io/github/license/google/promises.svg)](LICENSE)
[![Travis](https://api.travis-ci.org/google/promises.svg?branch=master)](https://travis-ci.org/google/promises)
[![Gitter Chat](https://badges.gitter.im/google/promises.svg)](https://gitter.im/google/promises)

![Platforms](https://img.shields.io/badge/platforms-macOS%20%7C%20iOS%20%7C%20tvOS%20%7C%20watchOS-blue.svg?longCache=true&style=flat)
![Languages](https://img.shields.io/badge/languages-Swift%20%7C%20ObjC-orange.svg?longCache=true&style=flat)
![Package Managers](https://img.shields.io/badge/supports-Bazel%20%7C%20SwiftPM%20%7C%20CocoaPods%20%7C%20Carthage-yellow.svg?longCache=true&style=flat)

# Promises

## 魔改内容
从 github 上 fork 下来的 [google/promises](https://github.com/google/promises).

* 新增了hotFulfill特性
* 新增了PromiseObjC.podspec（PromiseObjC.podspec的副本）
* 删除了Sources/FBLPromises/include/module.module_map，让PromiseObjC.podspec可以lint通过

## 官方Readme
Promises is a modern framework that provides a synchronization construct for
Objective-C and Swift to facilitate writing asynchronous code.

*   [Introduction](g3doc/index.md)
    *   [The problem with async
        code](g3doc/index.md#the-problem-with-async-code)
    *   [Promises to the rescue](g3doc/index.md#promises-to-the-rescue)
    *   [What is a promise?](g3doc/index.md#what-is-a-promise)
*   [Framework](g3doc/index.md#framework)
    *   [Features](g3doc/index.md#features)
    *   [Benchmark](g3doc/index.md#benchmark)
*   [Getting started](g3doc/index.md#getting-started)
    *   [Add dependency](g3doc/index.md#add-dependency)
    *   [Import](g3doc/index.md#import)
    *   [Adopt](g3doc/index.md#adopt)
*   [Basics](g3doc/index.md#basics)
    *   [Creating promises](g3doc/index.md#creating-promises)
        *   [Async](g3doc/index.md#async)
        *   [Do](g3doc/index.md#do)
        *   [Pending](g3doc/index.md#pending)
        *   [Resolved](g3doc/index.md#create-a-resolved-promise)
    *   [Observing fulfillment](g3doc/index.md#observing-fulfillment)
        *   [Then](g3doc/index.md#then)
    *   [Observing rejection](g3doc/index.md#observing-rejection)
        *   [Catch](g3doc/index.md#catch)
*   [Extensions](g3doc/index.md#extensions)
    *   [All](g3doc/index.md#all)
    *   [Always](g3doc/index.md#always)
    *   [Any](g3doc/index.md#any)
    *   [Await](g3doc/index.md#await)
    *   [Delay](g3doc/index.md#delay)
    *   [Race](g3doc/index.md#race)
    *   [Recover](g3doc/index.md#recover)
    *   [Reduce](g3doc/index.md#reduce)
    *   [Retry](g3doc/index.md#retry)
    *   [Timeout](g3doc/index.md#timeout)
    *   [Validate](g3doc/index.md#validate)
    *   [Wrap](g3doc/index.md#wrap)
*   [Advanced topics](g3doc/index.md#advanced-topics)
    *   [Default dispatch queue](g3doc/index.md#default-dispatch-queue)
    *   [Ownership and retain
        cycles](g3doc/index.md#ownership-and-retain-cycles)
    *   [Testing](g3doc/index.md#testing)
    *   [Objective-C <-> Swift
        interoperability](g3doc/index.md#objective-c---swift-interoperability)
    *   [Dot-syntax in Objective-C](g3doc/index.md#dot-syntax-in-objective-c)
*   [Anti-patterns](g3doc/index.md#anti-patterns)
    *   [Broken chain](g3doc/index.md#broken-chain)
    *   [Nested promises](g3doc/index.md#nested-promises)
