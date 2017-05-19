DJEncryptor 
==============

Simple AES, RSA encryption / decryption and Hash(MD5, HmacMD5, SHA1__SHA512, HmacSHA1__HmacSHA512) for iOS and OS X. <br/>

## Requirements

- iOS 4.0 or later
- Xcode 7.3 or later

## Frameworks

- libz

## Installation

1.You should copy below files to your projects:
`NSData+Encrypt.h`
`NSData+Encrypt.m`
`NSString+Encrypt.h`
`NSString+Encrypt.m`
`RSA.h`
`RSA.m`

2.Add under lines to your class:
``` objective-c
#import "NSData+Encrypt.h"
#import "NSString+Encrypt.h"
#import "RSA.h"
```

## Licenses

All source code is licensed under the [MIT License](https://github.com/iunion/DJEncryptor/blob/master/LICENSE).


## Usage

### Hash
``` objective-c
NSString *string = @"Do any additional setup after loading the view, typically from a nib.";
NSLog(@"md2: %@", [string md2String]);
NSLog(@"md4: %@", [string md4String]);
NSLog(@"md5: %@", [string md5String]);
NSLog(@"md516: %@", [string md5HexDigest16]);

NSLog(@"sha1: %@", [string sha1String]);
NSLog(@"sha224: %@", [string sha224String]);
NSLog(@"sha256: %@", [string sha256String]);
NSLog(@"sha384: %@", [string sha384String]);
NSLog(@"sha512: %@", [string sha512String]);

NSLog(@"hmacMD5: %@", [string hmacMD5StringWithKey:@"key"]);
NSLog(@"hmacSHA1: %@", [string hmacSHA1StringWithKey:@"key"]);
NSLog(@"hmacSHA224: %@", [string hmacSHA224StringWithKey:@"key"]);
NSLog(@"hmacSHA256: %@", [string hmacSHA256StringWithKey:@"key"]);
NSLog(@"hmacSHA384: %@", [string hmacSHA384StringWithKey:@"key"]);
NSLog(@"hmacSHA512: %@", [string hmacSHA512StringWithKey:@"key"]);
```

### Hash
``` objective-c
[string crc32String];
```

### Hash Output
``` objective-c
md2: b46270495c8196bbd8b8a4fd6e8a2d51
md4: f946d62ce4c188394f5eaf70e82263ab
md5: b0c65c1d384ef67d48e8a33a5487f6eb
md516: 384ef67d48e8a33a
sha1: 3cde1b400a9e7087a4e3a653c289e548e8fd23cc
sha224: 93517a39808d1ea1aac8da1de51b5ee3e20ee19c513fa939fa855718
sha256: 39d17b191f1e823e1931f308e41e864788323e510f29f8e747cdb75c9dd3ed89
sha384: 6a9af1b29ff994abc53e23f34660b910b43935a187f0079631f83cb04941eaf296271be6787f76affe23f12f29ad1aea
sha512: b5d963070647fbbb7188f156ca6f61051cc81caaf1cfb6292bd96fb42354cd1209816893302694ebeb5a3720a6d5dad837143cf4ccc5f7334622c2938e6bc700
hmacMD5: 447efbc0731643768648101661140df9
hmacSHA1: 3b1e1d77c14a1f79ed65fdd049a40ee9a3ad83c9
hmacSHA224: ea00c96da20bb216847583b2c7741258399a77fa2707494ce54628c7
hmacSHA256: e99e794409cd03eb961f894c91d9e6fc0aea3877bf4a71998d37f838d0a2daaa
hmacSHA384: ffb7f3ddb5fa0f99a079168aa8c1d03550253b5eaa86b09652bf2ce03e096458c384e77fd4969e99f4224b107bfe5638
hmacSHA512: e3c3dff4aee160163c896f2d6fbddaa3e85d35ee3aaafe6eaf2464e0f09a0acf553353d1df2740093a86a11483dadbe4e26634c93f646ef6bc19584489f4c094
crc32String: bb726d40
```

### Encrypt and Decrypt

- Encrypt
``` objective-c
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
initializationVector:(nullable id)iv
options:(CCOptions)options
error:(CCCryptorStatus *)error;
```

- Decrypt
``` objective-c
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
initializationVector:(nullable id)iv
options:(CCOptions)options
error:(CCCryptorStatus *)error;
```

### Sample for DES Encrypt and Decrypt
``` objective-c
NSString *string = @"Do any additional setup after loading the view, typically from a nib.";

encodeString = [string DESEncryptedDataUsingKey:@"12345678" iv:nil error:nil];
NSLog(@"%@", encodeString);
NSLog(@"%@", [encodeString DESDecryptedDataUsingKey:@"12345678" iv:nil error:nil]);

```
``` objective-c
670c1a49f0b76cad672226374722ded2237af9040af48c858680fd7f69dcfafa35e8bf71f450160e7f57ba77b3880c10b093f59ac175f9293fc16d1e4d353e33fd280b8d0b508692
Do any additional setup after loading the view, typically from a nib.
```

``` objective-c
/*
key:
enum {
kCCKeySizeAES128          = 16,
kCCKeySizeAES192          = 24,
kCCKeySizeAES256          = 32,
kCCKeySizeDES             = 8,
kCCKeySize3DES            = 24,
kCCKeySizeMinCAST         = 5,
kCCKeySizeMaxCAST         = 16,
kCCKeySizeMinRC4          = 1,
kCCKeySizeMaxRC4          = 512,
kCCKeySizeMinRC2          = 1,
kCCKeySizeMaxRC2          = 128,
kCCKeySizeMinBlowfish     = 8,
kCCKeySizeMaxBlowfish     = 56,
};

iv:
enum {
kCCBlockSizeAES128        = 16,
kCCBlockSizeDES           = 8,
kCCBlockSize3DES          = 8,
kCCBlockSizeCAST          = 8,
kCCBlockSizeRC2           = 8,
kCCBlockSizeBlowfish      = 8,
};
*/
```

length of `iv` is 8
``` objective-c
encodeString = [string DESEncryptedDataUsingKey:@"12345678" iv:@"12345678" error:nil];
NSLog(@"%@", encodeString);
NSLog(@"%@", [encodeString DESDecryptedDataUsingKey:@"12345678" iv:@"12345678" error:nil]);
```
``` objective-c
468ccd80798f771322fd4592228bdb07696bb6510861ee77ae871304bfffa35f9ad43e312da68247ef2e0f9006046274d8bf367b4f8a79893e692692814798e36adacc3f45d73a2e
Do any additional setup after loading the view, typically from a nib.
```
length of `iv` is 9
``` objective-c
encodeString = [string DESEncryptedDataUsingKey:@"12345678" iv:@"123456789" error:nil];
NSLog(@"%@", encodeString);
NSLog(@"%@", [encodeString DESDecryptedDataUsingKey:@"12345678" iv:@"123456789" error:nil]);
```
``` objective-c
468ccd80798f771322fd4592228bdb07696bb6510861ee77ae871304bfffa35f9ad43e312da68247ef2e0f9006046274d8bf367b4f8a79893e692692814798e36adacc3f45d73a2e
Do any additional setup after loading the view, typically from a nib.
```

### Inflate and deflate
``` objective-c
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
```

### RSA sample
``` objective-c
NSString* file = [[NSBundle mainBundle] pathForResource:@"rsa_private_key" ofType:@"pem"];
self.privateKeyPem = [NSString stringWithContentsOfFile:file encoding:NSUTF8StringEncoding error:nil];

file = [[NSBundle mainBundle] pathForResource:@"rsa_public_key" ofType:@"pem"];
self.publicKeyPem = [NSString stringWithContentsOfFile:file encoding:NSUTF8StringEncoding error:nil];

file = [[NSBundle mainBundle] pathForResource:@"rsa_public_key" ofType:@"der"];
self.publicKeyDer = [NSData dataWithContentsOfFile:file];

NSError *error = nil;

encodeString = [RSA encryptString:string publicPemKey:self.publicKeyPem error:&error];
NSLog(@"%@", encodeString);
NSString *decodeString = [RSA decryptString:encodeString privatePemKey:self.privateKeyPem error:nil];
NSLog(@"%@", decodeString);

encodeString = [RSA encryptString:string publicDer:self.publicKeyDer error:nil];
NSLog(@"%@", encodeString);
decodeString = [RSA decryptString:encodeString privatePemKey:self.privateKeyPem error:nil];
NSLog(@"%@", decodeString);
```
### RSA sample
// pem
T1tW5f9wUcbHXap7fTgSuT5HGZKBxq+N6Hypula4puWrW2FV1/rDG81TdWIF+eDOYL3YaEsYIIZ9Q9ZqrNDt6lwMrylyQLJoCVmHIIkxagYAwUTBz7tGKWV3mUXMD28hSIgoAmkUKCbmwwUp5fdFB4vzGuK3p0DuZ2njdIR1ApDQ3SlUXrFqAS4fWUd5bETF8bvwhFmVL+PwjNsii06ITPlQsa7ozoQR6U1Wfmp4cy9As9ir0qihQT1/XrKuyDOVYrXcgYGNlKGWxe/SLSuMjGZXBhArmLy/R29QmDLe9CkTBthP6Z1HqW3WRZKCgd7lDAhgZgGwYuGzOX1QdSC9Cg==
Do any additional setup after loading the view, typically from a nib.
// der
Xx3U3aKjJYgy69eav5QTPuK5skfdlGIGcT74MgxHxKQUM5K0WSotD0N5Um3qybohpQya8iQrxHoWA74/EPt4P2yCjxxohmd5OIBkvTCwXIx84qUafrmyYwG2mM9lL1V/4orN7/vi7OdnFIDSWafhLq54icbF0q6ejEx8ajWw+YdZAc0UvzD+KYiUPrM1hr4cwrwdKbNzcw2zSWUku61KwxHpr4aewFXqmSSGFwlKtU2VExkE6H1tcOow3Gm0t8vch7hnTZR8GFYBhMqJYwtbNxD687di7hCDAgpLA+wtYJJKoB4i7wh9NMzRAEd4N6lOpQRRnTwUqG9YQ35QZ1P6LQ==
Do any additional setup after loading the view, typically from a nib.
```

## Author
- [Dennis Deng](https://github.com/iunion)

