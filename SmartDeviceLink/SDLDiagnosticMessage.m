//  SDLDiagnosticMessage.m
//


#import "SDLDiagnosticMessage.h"

#import "SDLNames.h"

@implementation SDLDiagnosticMessage

- (instancetype)init {
    if (self = [super initWithName:SDLNameDiagnosticMessage]) {
    }
    return self;
}

- (void)setTargetID:(NSNumber *)targetID {
    if (targetID != nil) {
        [parameters setObject:targetID forKey:SDLNameTargetId];
    } else {
        [parameters removeObjectForKey:SDLNameTargetId];
    }
}

- (NSNumber *)targetID {
    return [parameters objectForKey:SDLNameTargetId];
}

- (void)setMessageLength:(NSNumber *)messageLength {
    if (messageLength != nil) {
        [parameters setObject:messageLength forKey:SDLNameMessageLength];
    } else {
        [parameters removeObjectForKey:SDLNameMessageLength];
    }
}

- (NSNumber *)messageLength {
    return [parameters objectForKey:SDLNameMessageLength];
}

- (void)setMessageData:(NSMutableArray *)messageData {
    if (messageData != nil) {
        [parameters setObject:messageData forKey:SDLNameMessageData];
    } else {
        [parameters removeObjectForKey:SDLNameMessageData];
    }
}

- (NSMutableArray *)messageData {
    return [parameters objectForKey:SDLNameMessageData];
}

@end
