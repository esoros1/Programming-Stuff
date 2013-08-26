//
//  ImageStore.m
//  PocketChange
//
//  Created by Tucker Cozzens on 3/9/13.
//  Copyright (c) 2013 Tucker Cozzens. All rights reserved.
//

#import "ImageStore.h"

static ImageStore *defaultImageStore = nil;

@implementation ImageStore


+ (id)allocWithZone:(NSZone *)zone{
    return [self defaultImageStore];
}
+ (ImageStore *)defaultImageStore
{
    if (!defaultImageStore) {
        // Create the singleton
        defaultImageStore = [[super allocWithZone:NULL] init];
    }
    return defaultImageStore;
}
- (id)init {
    if (defaultImageStore) {
        return defaultImageStore;
    }
    self = [super init];
    if (self) {
        dictionary = [[NSMutableDictionary alloc] init];
    }
    return self;
}

@end
