//
//  NSString+Encrypt.m
//  DJEncryptorSample
//
//  Created by DJ on 2017/5/4.
//  Copyright © 2017年 DJ. All rights reserved.
//

#import "NSString+Encrypt.h"
#import <CommonCrypto/CommonCrypto.h>
#import "GTMBase64.h"
#import "NSData+Encrypt.h"

@implementation NSString (Encrypt)

+ (NSString *)base64EncodeData:(NSData *)data
{
    NSData *encodeData = [data base64EncodedDataWithOptions:0];
    NSString *base64Str = [[NSString alloc] initWithData:encodeData encoding:NSUTF8StringEncoding];
    return base64Str;
}

+ (NSData *)base64DecodeString:(NSString *)base64Str
{
    NSData *data = [[NSData alloc] initWithBase64EncodedString:base64Str options:NSDataBase64DecodingIgnoreUnknownCharacters];
    return data;
}

#pragma mark - Hash

- (NSString *)md2String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] md2String];
}

- (NSString *)md4String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] md4String];
}

- (NSString *)md5String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] md5String];
}

- (NSString *)md5HexDigest16
{
    const char *original_str = [self UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    
    CC_MD5(original_str, (CC_LONG)strlen(original_str), result);
    
    NSMutableString *hash = [NSMutableString string];
    for (NSInteger i = 4; i < 12; i++)
    {
        [hash appendFormat:@"%02x", result[i]];
    }
    
    return hash;
}

- (NSString *)sha1String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] sha1String];
}

- (NSString *)sha224String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] sha224String];
}

- (NSString *)sha256String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] sha256String];
}

- (NSString *)sha384String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] sha384String];
}

- (NSString *)sha512String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] sha512String];
}

- (NSString *)hmacMD5StringWithKey:(NSString *)key
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            hmacMD5StringWithKey:key];
}

- (NSString *)hmacSHA1StringWithKey:(NSString *)key
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            hmacSHA1StringWithKey:key];
}

- (NSString *)hmacSHA224StringWithKey:(NSString *)key
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            hmacSHA224StringWithKey:key];
}

- (NSString *)hmacSHA256StringWithKey:(NSString *)key
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            hmacSHA256StringWithKey:key];
}

- (NSString *)hmacSHA384StringWithKey:(NSString *)key
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            hmacSHA384StringWithKey:key];
}

- (NSString *)hmacSHA512StringWithKey:(NSString *)key
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding]
            hmacSHA512StringWithKey:key];
}

- (NSString *)encodeGTMBase64
{
    return [GTMBase64 encodeBase64String:self];
}

- (NSString *)decodeGTMBase64
{
    return [GTMBase64 decodeBase64String:self];
}

- (NSString *)crc32String
{
    return [[self dataUsingEncoding:NSUTF8StringEncoding] crc32String];
}

#pragma mark - Encrypt and Decrypt

- (NSString *)AES256EncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSData *result = [data AES256EncryptedDataUsingKey:key iv:iv error:error];
    
    return [result lowerHexString];
}

- (NSString *)AES256DecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [NSData dataWithHexString:self];
    NSData *result = [data AES256DecryptedDataUsingKey:key iv:iv error:error];
    
    return [[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding];
}

- (NSString *)DESEncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSData *result = [data DESEncryptedDataUsingKey:key iv:iv error:error];
    
    return [result lowerHexString];
}

- (NSString *)DESDecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [NSData dataWithHexString:self];
    NSData *result = [data DESDecryptedDataUsingKey:key iv:iv error:error];
    
    return [[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding];
}

- (NSString *)TripleDESEncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSData *result = [data TripleDESEncryptedDataUsingKey:key iv:iv error:error];
    
    return [result lowerHexString];
}

- (NSString *)TripleDESDecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [NSData dataWithHexString:self];
    NSData *result = [data TripleDESDecryptedDataUsingKey:key iv:iv error:error];
    
    return [[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding];
}

- (NSString *)Base64AES256EncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSData *result = [data AES256EncryptedDataUsingKey:key iv:iv error:error];
    
    return [GTMBase64 encodeBase64Data:result];
}

- (NSString *)Base64AES256DecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [GTMBase64 decodeString:self];
    NSData *result = [data AES256DecryptedDataUsingKey:key iv:iv error:error];
    
    return [[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding];
}

- (NSString *)Base64DESEncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSData *result = [data DESEncryptedDataUsingKey:key iv:iv error:error];
    
    return [GTMBase64 encodeBase64Data:result];
}

- (NSString *)Base64DESDecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [GTMBase64 decodeString:self];
    NSData *result = [data DESDecryptedDataUsingKey:key iv:iv error:error];
    
    return [[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding];
}

- (NSString *)Base64TripleDESEncryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSData *result = [data TripleDESEncryptedDataUsingKey:key iv:iv error:error];
    
    return [GTMBase64 encodeBase64Data:result];
}

- (NSString *)Base64TripleDESDecryptedDataUsingKey:(id)key iv:(id)iv error:(NSError **)error
{
    NSData *data = [GTMBase64 decodeString:self];
    NSData *result = [data TripleDESDecryptedDataUsingKey:key iv:iv error:error];
    
    return [[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding];
}


#pragma mark - File hash

- (NSString *)fileMD5Hash
{
    return [NSData getFileMD5HashString:self];
}

- (NSString *)fileSHA1Hash
{
    return [NSData getFileSHA1HashString:self];
}

- (NSString *)fileSHA256Hash
{
    return [NSData getFileSHA256HashString:self];
}

- (NSString *)fileSHA512Hash
{
    return [NSData getFileSHA512HashString:self];
}

- (NSString *)fileCRC32SHash
{
    return [NSData getFileCRC32String:self];
}


@end
