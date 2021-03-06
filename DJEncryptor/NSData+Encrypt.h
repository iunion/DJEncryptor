//
//  NSData+Encrypt.h
//  DJEncryptorSample
//
//  Created by DJ on 2017/5/4.
//  Copyright © 2017年 DJ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>

extern NSString * _Nonnull const kDJEncryptErrorDomain;

NS_ASSUME_NONNULL_BEGIN

@interface NSError (Encrypt)

+ (NSError *)errorWithCCCryptorStatus:(CCCryptorStatus)status;

@end

@interface NSData (Encrypt)

#pragma mark - Hash

///=============================================================================
/// @name Hash
///=============================================================================

/**
 Returns a lowercase NSString for md2 hash.
 */
- (NSString *)md2String;

/**
 Returns an NSData for md2 hash.
 */
- (NSData *)md2Data;

/**
 Returns a lowercase NSString for md4 hash.
 */
- (NSString *)md4String;

/**
 Returns an NSData for md4 hash.
 */
- (NSData *)md4Data;

/**
 Returns a lowercase NSString for md5 hash.
 */
- (NSString *)md5String;

/**
 Returns an NSData for md5 hash.
 */
- (NSData *)md5Data;

/**
 Returns a lowercase NSString for sha1 hash.
 */
- (NSString *)sha1String;

/**
 Returns an NSData for sha1 hash.
 */
- (NSData *)sha1Data;

/**
 Returns a lowercase NSString for sha224 hash.
 */
- (NSString *)sha224String;

/**
 Returns an NSData for sha224 hash.
 */
- (NSData *)sha224Data;

/**
 Returns a lowercase NSString for sha256 hash.
 */
- (NSString *)sha256String;

/**
 Returns an NSData for sha256 hash.
 */
- (NSData *)sha256Data;

/**
 Returns a lowercase NSString for sha384 hash.
 */
- (NSString *)sha384String;

/**
 Returns an NSData for sha384 hash.
 */
- (NSData *)sha384Data;

/**
 Returns a lowercase NSString for sha512 hash.
 */
- (NSString *)sha512String;

/**
 Returns an NSData for sha512 hash.
 */
- (NSData *)sha512Data;

/**
 Returns a lowercase NSString for hmac using algorithm md5 with key.
 @param key  The hmac key.
 */
- (NSString *)hmacMD5StringWithKey:(NSString *)key;

/**
 Returns an NSData for hmac using algorithm md5 with key.
 @param key  The hmac key.
 */
- (NSData *)hmacMD5DataWithKey:(NSData *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha1 with key.
 @param key  The hmac key.
 */
- (NSString *)hmacSHA1StringWithKey:(NSString *)key;

/**
 Returns an NSData for hmac using algorithm sha1 with key.
 @param key  The hmac key.
 */
- (NSData *)hmacSHA1DataWithKey:(NSData *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha224 with key.
 @param key  The hmac key.
 */
- (NSString *)hmacSHA224StringWithKey:(NSString *)key;

/**
 Returns an NSData for hmac using algorithm sha224 with key.
 @param key  The hmac key.
 */
- (NSData *)hmacSHA224DataWithKey:(NSData *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha256 with key.
 @param key  The hmac key.
 */
- (NSString *)hmacSHA256StringWithKey:(NSString *)key;

/**
 Returns an NSData for hmac using algorithm sha256 with key.
 @param key  The hmac key.
 */
- (NSData *)hmacSHA256DataWithKey:(NSData *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha384 with key.
 @param key  The hmac key.
 */
- (NSString *)hmacSHA384StringWithKey:(NSString *)key;

/**
 Returns an NSData for hmac using algorithm sha384 with key.
 @param key  The hmac key.
 */
- (NSData *)hmacSHA384DataWithKey:(NSData *)key;

/**
 Returns a lowercase NSString for hmac using algorithm sha512 with key.
 @param key  The hmac key.
 */
- (NSString *)hmacSHA512StringWithKey:(NSString *)key;

/**
 Returns an NSData for hmac using algorithm sha512 with key.
 @param key  The hmac key.
 */
- (NSData *)hmacSHA512DataWithKey:(NSData *)key;

/**
 Returns a lowercase NSString for crc32 hash.
 */
- (NSString *)crc32String;

/**
 Returns crc32 hash.
 */
- (uint32_t)crc32;


#pragma mark - Encrypt and Decrypt

///=============================================================================
/// @name Encrypt and Decrypt
///=============================================================================

/**
 Returns an encrypted NSData using an algorithm.
 
 @param algorithm   An algorithm(AES, DES ...).

 @param key         A key length of 16, 24 or 32 (128, 192 or 256bits).
                    NSData or NSString.
 
 @param iv          An initialization vector length of 16(128bits).
                    Pass nil when you don't want to use iv.
                    NSData or NSString.
 
 @return            An NSData encrypted, or nil if an error occurs.
 */
- (nullable NSData *)dataEncryptedUsingAlgorithm:(CCAlgorithm)algorithm
                                    key:(id)key
                                  error:(CCCryptorStatus *)error;
- (nullable NSData *)dataEncryptedUsingAlgorithm:(CCAlgorithm)algorithm
                                    key:(id)key
                                options:(CCOptions)options
                                  error:(CCCryptorStatus *)error;
- (nullable NSData *)dataEncryptedUsingAlgorithm:(CCAlgorithm)algorithm
                                    key:(id)key
                   initializationVector:(nullable id)iv
                                options:(CCOptions)options
                                  error:(CCCryptorStatus *)error;

/**
 Returns an decrypted NSData using an algorithm.
 
 @param algorithm   An algorithm(AES, DES ...).
 
 @param key         A key length of 16, 24 or 32 (128, 192 or 256bits).
                    NSData or NSString.
 
 @param iv          An initialization vector length of 16(128bits).
                    Pass nil when you don't want to use iv.
                    NSData or NSString.
 
 @return            An NSData encrypted, or nil if an error occurs.
 */
- (nullable NSData *)dataDecryptedUsingAlgorithm:(CCAlgorithm)algorithm
                                    key:(id)key
                                  error:(CCCryptorStatus *)error;
- (nullable NSData *)dataDecryptedUsingAlgorithm:(CCAlgorithm)algorithm
                                    key:(id)key
                                options:(CCOptions)options
                                  error:(CCCryptorStatus *)error;
- (nullable NSData *)dataDecryptedUsingAlgorithm:(CCAlgorithm)algorithm
                                    key:(id)key
                   initializationVector:(nullable id)iv
                                options:(CCOptions)options
                                  error:(CCCryptorStatus *)error;

/**
 Returns an encrypted NSData or an decrypted NSData using an algorithm.
 
 @param algorithm           Defines the encryption algorithm(AES, DES ...).
 
 @param encryptOrDecrypt    Defines the basic operation: kCCEncrypt or kCCDecrypt.
 
 @param key                 A key length of 16, 24 or 32 (128, 192 or 256bits).
                            NSData or NSString.
 
 @param iv                  An initialization vector length of 16(128bits).
                            Pass nil when you don't want to use iv.
                            NSData or NSString.
 
 @param options             A word of flags defining options.
 
 @return                    An NSData encrypted, or nil if an error occurs.
 */
- (nullable NSData *)dataUsingAlgorithm:(CCAlgorithm)algorithm
              encryptOrDecrypt:(CCOperation)encryptOrDecrypt
                           key:(id)key
          initializationVector:(nullable id)iv
                       options:(CCOptions)options
                         error:(CCCryptorStatus *)error;

// AES
- (nullable NSData *)AES256EncryptedDataUsingKey:(id)key iv:(nullable id)iv error:(NSError **)error;
- (nullable NSData *)AES256DecryptedDataUsingKey:(id)key iv:(nullable id)iv error:(NSError **)error;
// DES
- (nullable NSData *)DESEncryptedDataUsingKey:(id)key iv:(nullable id)iv error:(NSError **)error;
- (nullable NSData *)DESDecryptedDataUsingKey:(id)key iv:(nullable id)iv error:(NSError **)error;
- (nullable NSData *)TripleDESEncryptedDataUsingKey:(id)key iv:(nullable id)iv error:(NSError **)error;
- (nullable NSData *)TripleDESDecryptedDataUsingKey:(id)key iv:(nullable id)iv error:(NSError **)error;


#pragma mark - Encode and decode

///=============================================================================
/// @name Encode and decode
///=============================================================================

/**
 Returns string decoded in UTF8.
 */
- (NSString *)utf8String;

/**
 Returns a uppercase NSString in HEX.
 */
- (NSString *)hexString;

/**
 Returns a lowercase NSString in HEX.
 */
- (NSString *)lowerHexString;

/**
 Returns an NSData from hex string.
 
 @param hexString   The hex string which is case insensitive.
 
 @return a new NSData, or nil if an error occurs.
 */
+ (NSData *)dataWithHexString:(NSString *)hexString;


#pragma mark - Inflate and deflate
///=============================================================================
/// @name Inflate and deflate
///=============================================================================

/**
 Decompress data from gzip data.
 @return Inflated data.
 */
- (nullable NSData *)gzipInflate;

/**
 Comperss data to gzip in default compresssion level.
 @return Deflated data.
 */
- (nullable NSData *)gzipDeflate;

/**
 Decompress data from zlib-compressed data.
 @return Inflated data.
 */
- (nullable NSData *)zlibInflate;

/**
 Comperss data to zlib-compressed in default compresssion level.
 @return Deflated data.
 */
- (nullable NSData *)zlibDeflate;


#pragma mark - File hash

/**
 Returns a NSData for md5 hash of the file.
 
 @param filePath   The file.
 */
+ (nullable NSData *)getFileMD5HashData:(NSString *)filePath;
/**
 Returns a lowercase string for md5 hash of the file.
 
 @param filePath   The file.
 */
+ (nullable NSString *)getFileMD5HashString:(NSString *)filePath;

+ (nullable NSData *)getFileSHA1HashData:(NSString *)filePath;
+ (nullable NSString *)getFileSHA1HashString:(NSString *)filePath;

+ (nullable NSData *)getFileSHA256HashData:(NSString *)filePath;
+ (nullable NSString *)getFileSHA256HashString:(NSString *)filePath;

+ (nullable NSData *)getFileSHA512HashData:(NSString *)filePath;
+ (nullable NSString *)getFileSHA512HashString:(NSString *)filePath;

/**
 Returns crc32 hash of a file.

 @param filePath   The file.
 */
+ (unsigned long)getFileCRC32:(NSString *)filePath;
+ (NSString *)getFileCRC32String:(NSString *)filePath;

@end

NS_ASSUME_NONNULL_END

