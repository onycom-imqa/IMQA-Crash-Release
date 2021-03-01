Pod::Spec.new do |s|
  s.name             = 'IMQACrash'
  s.version          = '3.0.0'
  s.summary          = 'Crash Report SDK for iOS by IMQA'

  s.description      = 'This Framework is Crash Report SDK for iOS by IMQA'

  s.homepage         = 'http://imqa.io/'
  s.license          = { :type => 'Commercial', :file => 'IMQACrash.framework/LICENSE' }
  s.author           = { 'Onycom, Inc.' => 'support@imqa.io' }
  s.source           = { :http  => "https://github.com/onycom-imqa/IMQA-Crash-Release/releases/download/v3.0.0/IMQACrash.zip" }

  s.ios.deployment_target = '9.3'

  s.source_files = 'IMQACrash.framework/**/*.h'
  s.vendored_frameworks = 'IMQACrash.framework'
  s.preserve_paths = '*.framework'

  s.frameworks = 'Foundation', 'SystemConfiguration', 'Security'
  s.libraries = 'c++', 'z'
end