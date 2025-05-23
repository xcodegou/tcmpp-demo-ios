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

#import "TFBLPromise+Reduce.h"

#import "TFBLPromisePrivate.h"

@implementation TFBLPromise (ReduceAdditions)

- (TFBLPromise *)reduce:(NSArray *)items combine:(TFBLPromiseReducerBlock)reducer {
  return [self onQueue:TFBLPromise.defaultDispatchQueue reduce:items combine:reducer];
}

- (TFBLPromise *)onQueue:(dispatch_queue_t)queue
                 reduce:(NSArray *)items
                combine:(TFBLPromiseReducerBlock)reducer {
  NSParameterAssert(queue);
  NSParameterAssert(items);
  NSParameterAssert(reducer);

  TFBLPromise *promise = self;
  for (id item in items) {
    promise = [promise chainOnQueue:queue
                     chainedFulfill:^id(id value) {
                       return reducer(value, item);
                     }
                      chainedReject:nil];
  }
  return promise;
}

@end

@implementation TFBLPromise (DotSyntax_ReduceAdditions)

- (TFBLPromise * (^)(NSArray *, TFBLPromiseReducerBlock))reduce {
  return ^(NSArray *items, TFBLPromiseReducerBlock reducer) {
    return [self reduce:items combine:reducer];
  };
}

- (TFBLPromise * (^)(dispatch_queue_t, NSArray *, TFBLPromiseReducerBlock))reduceOn {
  return ^(dispatch_queue_t queue, NSArray *items, TFBLPromiseReducerBlock reducer) {
    return [self onQueue:queue reduce:items combine:reducer];
  };
}

@end
