project(
  'yap',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1.0',
  default_options : ['warning_level=3', 'c_std=23'],
)

curl = dependency('libcurl')
solv = dependency('libsolv')

dependencies = [
	curl, 
	solv,
]

sources = [
  'src/main.c', 
  'src/package.c', 
  'src/resolver.c', 
  'src/downloader.c', 
  'src/installer.c',
]

executable(
  'yap',
  sources,
  include_directories : include_directories('include'),
  dependencies : dependencies,
  install : true,
)
