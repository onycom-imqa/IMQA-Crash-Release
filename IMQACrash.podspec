Pod::Spec.new do |s|
  s.name             = 'IMQACrash'
  s.version          = '3.0.2'
  s.summary          = 'Crash Report SDK for iOS by IMQA'

  s.description      = 'This Framework is Crash Report SDK for iOS by IMQA'

  s.homepage         = 'http://imqa.io/'
  s.license          = { :type => 'Commercial', :file => 'IMQACrash.framework/LICENSE' }
  s.author           = { 'Onycom, Inc.' => 'support@imqa.io' }
  s.source           = { :http  => "https://github.com/onycom-imqa/IMQA-Crash-Release/releases/download/v3.0.2/IMQACrash.zip" }

  s.ios.deployment_target = '9.3'

  s.xcconfig     =  { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/IMQACrash/"' }

  s.source_files = 'IMQACrash.xcframework/ios-arm64_armv7/IMQACrash.framework/Headers/*.{h}'
  s.vendored_frameworks = 'IMQACrash.xcframework'
  s.preserve_paths =  'IMQACrash.xcframework/*'

  s.frameworks = 'Foundation', 'SystemConfiguration', 'Security'
  s.libraries = 'c++', 'z'
end