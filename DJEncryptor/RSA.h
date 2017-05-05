//
//  RSA.h
//  DJEncryptorSample
//
//  Created by DJ on 2017/5/5.
//  Copyright © 2017年 DJ. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kDJRSAErrorDomain;

@interface NSError (RSA)

+ (NSError *)errorWithRSAOSStatus:(OSStatus)status;
+ (NSError *)errorWithRSADescription:(NSString *)description reason:(NSString *)reason status:(OSStatus)status;
+ (NSError *)errorWithRSADescription:(NSString *)description;

@end

@interface RSA : NSObject

#pragma mark PEM加密
+ (NSData *)encryptWithString:(NSString *)string publicPemKey:(NSString *)pubKey error:(NSError **)error;
+ (NSData *)encryptWithData:(NSData *)data publicPemKey:(NSString *)pubKey error:(NSError **)error;

+ (NSString *)encryptString:(NSString *)string publicPemKey:(NSString *)pubKey error:(NSError **)error;
+ (NSString *)encryptData:(NSData *)data publicPemKey:(NSString *)pubKey error:(NSError **)error;

#pragma mark DER加密
+ (NSData *)encryptWithString:(NSString *)string publicDer:(NSData *)derFileData error:(NSError **)error;
+ (NSData *)encryptWithData:(NSData *)data publicDer:(NSData *)derFileData error:(NSError **)error;

+ (NSString *)encryptString:(NSString *)string publicDer:(NSData *)derFileData error:(NSError **)error;
+ (NSString *)encryptData:(NSData *)data publicDer:(NSData *)derFileData error:(NSError **)error;

#pragma mark PEM解密 publicPemKey
+ (NSData *)decryptWithString:(NSString *)string publicPemKey:(NSString *)pubKey error:(NSError **)error;
+ (NSData *)decryptWithData:(NSData *)data publicPemKey:(NSString *)pubKey error:(NSError **)error;

+ (NSString *)decryptString:(NSString *)string publicPemKey:(NSString *)pubKey error:(NSError **)error;
+ (NSString *)decryptData:(NSData *)data publicPemKey:(NSString *)pubKey error:(NSError **)error;

#pragma mark PEM解密 privatePemKey
+ (NSData *)decryptWithString:(NSString *)string privatePemKey:(NSString *)privKey error:(NSError **)error;
+ (NSData *)decryptWithData:(NSData *)data privatePemKey:(NSString *)privKey error:(NSError **)error;

+ (NSString *)decryptString:(NSString *)string privatePemKey:(NSString *)privKey error:(NSError **)error;
+ (NSString *)decryptData:(NSData *)data privatePemKey:(NSString *)privKey error:(NSError **)error;

@end
