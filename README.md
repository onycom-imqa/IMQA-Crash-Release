# IMQA Crash SDK 설치 가이드 

IMQA Crash 을 iOS 프로젝트에 추가하면, Objective-C 및 Swift 로 개발한 앱에서 발생하는 어플리케이션의 성능 문제를 다양한 시각으로 확인할 수 있습니다.

> **iOS SDK 문의** </br>
> 이메일 : ybcha@onycom.com

### 시스템 요구사항 

* iOS XX 이상 
* Xcode XX 이상 

---

## 1. 프레임워크 설치 

IMQA Crash SDK는 2가지 방식으로 SDK를 설치 방법을 제공하고 있습니다. 사용하고 계신 환경에 맞춰서 설치를 진행하시면 됩니다.

### XCFrameworks 

[프레임워크 다운로드]() 

위 링크를 통해 프레임워크를 다운로드 후, Targets > [Project Name] > General > Frameworks, Libraries, and Embedded Content 로 옮겨주세요.

### Cocoapods 

Podfile 에 다음과 같이 추가 후 `pod install`를 터미널에서 실행해주세요. 
```Podfile 

pod 'IMQACrashAgent', '~> 3.1.0'

```

위 2가지 방식 외에 원하시는 설치 방식이 있으신 경우, ybcha@onycom.com으로 문의 주시면 감사하겠습니다. 

</br>

## 2. 초기화 코드 작성하기 

자신의 프로젝트에서 사용하는 언어에 맞춰 초기화 코드를 작성해주시길 바랍니다. 

### Objective-C 

```Objectivec
```

### Swift 

```swift 
```

</br>

## 3. (선택) 설치형 고객사 수집 서버 설정

IMQA 솔루션이 기업 내 설치형 서버로 구축되어 있는 경우, 데이터를 전송하는 수집 서버 경로를 설정해주시길 바랍니다
별도로 설정이 아닌 프레임워크 내에 수집 서버를 설정되어 있는 상태를 원하시는 경우 ybcha@onycom.com으로 문의를 주시면 수집 경로를 고객사에 맞게 커스터마이징을 해서 프레임워크 파일을 전달 해 드리겠습니다. 

### Objective-C 

```Objectivec
NSString* imqaUrl = @"https://custom-url";
IMQACrashConfiguration* crashConfig = [[IMQACrashConfiguration alloc] initWithApiKey:PROJECT_KEY];

IMQACrashEndpointConfiguration* endpoint = [[IMQACrashEndpointConfiguration alloc] init]; 
endpoint.notify = imqaUrl + @"/cocoa/crash/send";
endpoint.sessions = imqaUrl + @"/cocoa/session"; 
crashConfig.endpoints = endpoint;
```

### Swift 

```swift 
let imqaUrl = "https://custom-url"
let crashConfig = IMQACrashConfiguration("<PROJECT_KEY>")
crashConfig.endpoints = IMQACrashEndpointConfiguration(
                                 notify: imqaUrl + "/cocoa/crash/send",
                                 sessions: imqaUrl + "/cocoa/session")
```

</br>

## 4. 커스텀 에러 전송하기 

크래시 뿐만 아니라 별도로 Error들을 Catch 하고 계신 경우, 아래 방식으로 에러를 보내주시면 솔루션에서 확인이 가능합니다. 

### Objective-C 

```Objectivec
#import <IMQACrash/IMQACrash.h>

NSError* custom_error = [NSError errorWithDomain:@"custom_error" code:404 userInfo:NULL];
[IMQACrash notifyError:custom_error];
```

### Swift 

```swift 
import IMQACrash

let custom_error = NSError(domain: "custom error", code: 404, userInfo: nil)
IMQACrash.notifyError(custom_error)
```

</br>

## 5. 향후 업데이트 내용 

향후 아래와 같은 기능이 추가 될 예정입니다. 구체적인 일정은 정해진 것이 없으며, 업데이트 소식은 blog.imqa.io 에서 확인 하실 수 있습니다. 

**IMQA Crash for iOS Roadmap** 
1. Custom Logging  
2. Application Not Reponse (10sec) (Custom time) 
3. Out Of Memory Crash 
4. Remote Config

원하시는 Crash 솔루션 기능이 있으신 경우에 ybcha@onycom.com으로 많은 의견 부탁드립니다. 

