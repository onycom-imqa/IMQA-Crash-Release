
Pod::Spec.new do |s|
  s.name             = 'IMQACrashAgent'
  version            = '3.5.0'
  s.version          = version
  s.summary          = 'Crash Report SDK for iOS by IMQA'

  s.description      = 'This Framework is Crash Report SDK for iOS by IMQA'

  s.homepage         = 'http://imqa.io/'
  s.license          = { :type => 'Commercial', :file => 'IMQACrashAgent.xcframework/ios-arm64_armv7/IMQACrashAgent.framework/LICENSE' }
  s.author           = { 'Onycom, Inc.' => 'support@imqa.io' }
  s.source           = { :http  => "https://github.com/onycom-imqa/IMQA-Crash-Release/releases/download/v#{s.version}/IMQACrashAgent.zip" }

  s.ios.deployment_target = '9.0'

  s.xcconfig     =  { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/IMQACrashAgent/"' }

  s.source_files = 'IMQACrashAgent.xcframework/ios-arm64_armv7/IMQACrashAgent.framework/Headers/*.{h}'
  s.vendored_frameworks = 'IMQACrashAgent.xcframework'
  s.preserve_paths =  'IMQACrashAgent.xcframework/*'

  s.frameworks = 'Foundation', 'SystemConfiguration', 'Security'
  s.libraries = 'c++', 'z'
end
