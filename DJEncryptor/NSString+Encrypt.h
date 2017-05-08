//
//  NSString+Encrypt.h
//  DJEncryptorSample
//
//  Created by DJ on 2017/5/4.
//  Copyright © 2017年 DJ. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Encrypt)

/**
 Returns a NSString for base64 encoded.
 */
+ (NSString *)base64EncodeData:(NSData *)data;

/**
 Returns a NSData for base64 decoded.
 */
+ (NSData *)base64DecodeString:(NSString *)base64Str;

#pragma mark - Hash

/**
 Returns a lowercase NSString for md2 hash.
 */
- (NSString *)md2String;

/**
 Returns a lowercase NSString for md4 hash.
 */
- (NSString *)md4String;

/**
 Returns a lowercase NSString for md5 hash.
 */
- (NSString *)md5String;
- (NSString *)md5HexDigest16;

/**
 Returns a lowercase NSString for sha1 hash.
 */
- (NSString *)sha1String;

/**
 Returns a lowercase NSString for sha224 hash.
 */
- (NSString *)sha224String;

/**
 Returns a lowercase NSString for sha256 hash.
 */
- (NSString *)sha256String;

/**
 Returns a lowercase NSString for sha384 hash.
 */
- (NSString *)sha384String;

/**
 Returns a lowercase NSString for sha512 hash.
 */
- (NSString *)sha512String;

/**
 Returns a lowercase NSString for hmac using algorithm md5 with key.
 @param key The hmac key.
 */
- (NSString *)hmacMD5StringWithKey:(NSString *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha1 with key.
 @param key The hmac key.
 */
- (NSString *)hmacSHA1StringWithKey:(NSString *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha224 with key.
 @param key The hmac key.
 */
- (NSString *)hmacSHA224StringWithKey:(NSString *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha256 with key.
 @param key The hmac key.
 */
- (NSString *)hmacSHA256StringWithKey:(NSString *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha384 with key.
 @param key The hmac key.
 */
- (NSString *)hmacSHA384StringWithKey:(NSString *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha512 with key.
 @param key The hmac key.
 */
- (NSString *)hmacSHA512StringWithKey:(NSString *)key;

/**
 Returns a lowercase NSString for crc32 hash.
 */
- (NSString *)crc32String;

#pragma mark - Encrypt and Decrypt

/**
 Returns an encrypted lowercase NSString in hex using an algorithm(AES, DES ...).
 
  @param key        A key length of 16, 24 or 32 (128, 192 or 256bits).
                    NSData or NSString.
 
 @param iv          An initialization vector length of 16(128bits).
                    Pass nil when you don't want to use iv.
                    NSData or NSString.
 
 @return            An NSData encrypted, or nil if an error occurs.
 */
- (NSString *)AES256EncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)AES256DecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)DESEncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)DESDecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)TripleDESEncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)TripleDESDecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;

/**
 Returns an encrypted base64 encoded NSString using an algorithm(AES, DES ...).
 
 @param key         A key length of 16, 24 or 32 (128, 192 or 256bits).
                    NSData or NSString.
 
 @param iv          An initialization vector length of 16(128bits).
                    Pass nil when you don't want to use iv.
                    NSData or NSString.
 
 @return            An NSData encrypted, or nil if an error occurs.
 */
- (NSString *)Base64AES256EncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)Base64AES256DecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)Base64DESEncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)Base64DESDecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)Base64TripleDESEncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;
- (NSString *)Base64TripleDESDecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error;


#pragma mark - File hash

- (NSString *)fileMD5Hash;

- (NSString *)fileSHA1Hash;

- (NSString *)fileSHA256Hash;

- (NSString *)fileSHA512Hash;

- (NSString *)fileCRC32SHash;


@end
