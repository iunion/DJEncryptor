//
//  ViewController.m
//  DJEncryptorSample
//
//  Created by DJ on 2017/5/4.
//  Copyright © 2017年 DJ. All rights reserved.
//

#import "ViewController.h"
#import "NSString+Encrypt.h"
#import "RSA.h"

@interface ViewController ()

@property(nonatomic, copy) NSString *privateKeyPem;
@property(nonatomic, copy) NSString *publicKeyPem;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
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
    
    NSString *encodeString;
    
    NSLog(@"crc32String: %@", [string crc32String]);
    
    encodeString = [string DESEncryptedDataUsingKey:@"12345678" iv:@"12345678" error:nil];
    NSLog(@"%@", encodeString);
    NSLog(@"%@", [encodeString DESDecryptedDataUsingKey:@"12345678" iv:@"12345678" error:nil]);

    // 和上面的比较结果一样，注意key和iv的长度限制
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
    encodeString = [string DESEncryptedDataUsingKey:@"123456789" iv:@"123456789" error:nil];
    NSLog(@"%@", encodeString);
    NSLog(@"%@", [encodeString DESDecryptedDataUsingKey:@"123456789" iv:@"123456789" error:nil]);
    
    
    
    NSString* file = [[NSBundle mainBundle]pathForResource:@"rsa_private_key" ofType:@"pem"];
    self.privateKeyPem = [NSString stringWithContentsOfFile:file encoding:NSUTF8StringEncoding error:nil];
    
    file = [[NSBundle mainBundle]pathForResource:@"rsa_public_key" ofType:@"pem"];
    self.publicKeyPem = [NSString stringWithContentsOfFile:file encoding:NSUTF8StringEncoding error:nil];
    
    NSError *error = nil;

    encodeString = [RSA encryptString:string publicPemKey:self.publicKeyPem error:&error];
    NSLog(@"%@", encodeString);
    NSString *decodeString = [RSA decryptString:encodeString privatePemKey:self.privateKeyPem error:nil];
    NSLog(@"%@", decodeString);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
