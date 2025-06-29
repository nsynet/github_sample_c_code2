_nisy__sources = [
  'main.c',
  '_nisy_-window.c',
]

_nisy__deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

_nisy__sources += gnome.compile_resources('_nisy_-resources',
  '_nisy_.gresource.xml',
  c_name: '_nisy_'
)

executable('_nisy_', _nisy__sources,
  dependencies: _nisy__deps,
  install: true,
)
