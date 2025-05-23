/**
 Copyright 2018 Google Inc. All rights reserved.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at:

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import "TFBLPromise+Testing.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Miscellaneous low-level private interfaces available to extend standard TFBLPromise functionality.
 */
@interface TFBLPromise<Value>()

typedef void (^TFBLPromiseOnFulfillBlock)(Value __nullable value) NS_SWIFT_UNAVAILABLE("");
typedef void (^TFBLPromiseOnRejectBlock)(NSError *error) NS_SWIFT_UNAVAILABLE("");
typedef id __nullable (^__nullable TFBLPromiseChainedFulfillBlock)(Value __nullable value)
    NS_SWIFT_UNAVAILABLE("");
typedef id __nullable (^__nullable TFBLPromiseChainedRejectBlock)(NSError *error)
    NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise.
 */
- (instancetype)initPending NS_SWIFT_UNAVAILABLE("");

/**
 Creates a resolved promise.

 @param resolution An object to resolve the promise with: either a value or an error.
 @return A new resolved promise.
 */
- (instancetype)initWithResolution:(nullable id)resolution NS_SWIFT_UNAVAILABLE("");

/**
 Invokes `fulfill` and `reject` blocks on `queue` when the receiver gets either fulfilled or
 rejected respectively.
 */
- (void)observeOnQueue:(dispatch_queue_t)queue
               fulfill:(TFBLPromiseOnFulfillBlock)onFulfill
                reject:(TFBLPromiseOnRejectBlock)onReject NS_SWIFT_UNAVAILABLE("");

- (void)observeOnQueue:(dispatch_queue_t)queue
              addOwner:(_Nullable id)owner
               fulfill:(TFBLPromiseOnFulfillBlock)onFulfill
                reject:(TFBLPromiseOnRejectBlock)onReject NS_SWIFT_UNAVAILABLE("");

/**
 Returns a new promise which gets resolved with the return value of `chainedFulfill` or
 `chainedReject` blocks respectively. The blocks are invoked when the receiver gets either
 fulfilled or rejected. If `nil` is passed to either block arg, the returned promise is resolved
 with the same resolution as the receiver.
 */
- (TFBLPromise *)chainOnQueue:(dispatch_queue_t)queue
              chainedFulfill:(TFBLPromiseChainedFulfillBlock)chainedFulfill
               chainedReject:(TFBLPromiseChainedRejectBlock)chainedReject NS_SWIFT_UNAVAILABLE("");

- (TFBLPromise *)chainOnQueue:(dispatch_queue_t)queue
                  addOwner:(nullable id)owner
              chainedFulfill:(TFBLPromiseChainedFulfillBlock)chainedFulfill
               chainedReject:(TFBLPromiseChainedRejectBlock)chainedReject
                   NS_SWIFT_UNAVAILABLE("");

@end

NS_ASSUME_NONNULL_END
