//
//  MCOAbstractPart.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 3/10/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef MAILCORE_MCOABSTRACTPART_H

#define MAILCORE_MCOABSTRACTPART_H

#import <Foundation/Foundation.h>

@class MCOAbstractMessage;

typedef NS_ENUM(NSInteger, MCOPartType) {
    // Used for a single part.
    // The part will be a MCOAbstractPart.
    MCOPartTypeSingle,
    
    // Used for a message part (MIME type: message/rfc822).
    // The part will be a MCOAbstractMessagePart.
    // It's when a message is sent as attachment of an other message.
    MCOPartTypeMessage,
    
    // Used for a multipart, multipart/mixed.
    // The part will be a MCOAbstractMultipart.
    MCOPartTypeMultipartMixed,
    
    // Used for a multipart, multipart/related.
    // The part will be a MCOAbstractMultipart.
    MCOPartTypeMultipartRelated,
    
    // Used for a multipart, multipart/alternative.
    // The part will be a MCOAbstractMultipart.
    MCOPartTypeMultipartAlternative,
    
    // Used for a signed message, multipart/signed.
    // The part will be a MCOAbstractMultipart.
    MCOPartTypeMultipartSigned,
};

#ifdef __cplusplus
namespace mailcore {
    class AbstractPart;
}
#endif

@interface MCOAbstractPart : NSObject <NSCopying>

#ifdef __cplusplus
- (instancetype _Nonnull) initWithMCPart:(mailcore::AbstractPart *)part NS_DESIGNATED_INITIALIZER;
#endif

/** Returns type of the part (single / message part / multipart/mixed,
 multipart/related, multipart/alternative). See MCOPartType.*/
@property (nonatomic, assign) MCOPartType partType;

/** Returns filename of the part.*/
@property (nonatomic, copy) NSString * _Nullable filename;

/** Returns MIME type of the part. For example application/data.*/
@property (nonatomic, copy) NSString * _Nullable mimeType;

/** Returns charset of the part in case it's a text single part.*/
@property (nonatomic, copy) NSString * _Nullable charset;

/** Returns the unique ID generated for this part.
 It's a unique identifier that's created when the object is created manually
 or created by the parser.*/
@property (nonatomic, copy) NSString * _Nullable uniqueID;

/** Returns the value of the Content-ID field of the part.*/
@property (nonatomic, copy) NSString * _Nullable contentID;

/** Returns the value of the Content-Location field of the part.*/
@property (nonatomic, copy) NSString * _Nullable contentLocation;

/** Returns the value of the Content-Description field of the part.*/
@property (nonatomic, copy) NSString * _Nullable contentDescription;

/** Returns whether the part is an explicit inline attachment.*/
@property (nonatomic, assign, getter=isInlineAttachment) BOOL inlineAttachment;

/** Returns whether the part is an explicit attachment.*/
@property (nonatomic, assign, getter=isAttachment) BOOL attachment;

/** Returns the part with the given Content-ID among this part and its subparts.*/
- (MCOAbstractPart * _Nullable) partForContentID:(NSString * _Nonnull)contentID;

/** Returns the part with the given unique identifier among this part and its subparts.*/
- (MCOAbstractPart * _Nullable) partForUniqueID:(NSString * _Nonnull)uniqueID;

/** Returns a string representation of the data according to charset.*/
- (NSString * _Nullable) decodedStringForData:(NSData * _Nonnull)data;

/** Adds a content type parameter.*/
- (void) setContentTypeParameterValue:(NSString * _Nonnull)value forName:(NSString * _Nonnull)name;

/** Remove a given content type parameter.*/
- (void) removeContentTypeParameterForName:(NSString * _Nonnull)name;

/** Returns the value of a given content type parameter.*/
- (NSString * _Nullable) contentTypeParameterValueForName:(NSString * _Nonnull)name;

/** Returns an array with the names of all content type parameters.*/
- (NSArray * _Nullable /* NSString */) allContentTypeParametersNames;

#pragma mark - Unavailable initializers
/** Do not invoke this directly. */
- (instancetype _Nonnull) init NS_UNAVAILABLE;
/** Do not invoke this directly. */
+ (instancetype _Nonnull) new NS_UNAVAILABLE;

@end

#endif
