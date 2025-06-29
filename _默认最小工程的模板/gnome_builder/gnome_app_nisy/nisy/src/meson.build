nisy_sources = [
  'main.c',
  'nisy-window.c',
]

nisy_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

nisy_sources += gnome.compile_resources('nisy-resources',
  'nisy.gresource.xml',
  c_name: 'nisy'
)

executable('nisy', nisy_sources,
  dependencies: nisy_deps,
  install: true,
)
