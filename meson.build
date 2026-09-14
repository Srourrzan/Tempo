project('Tempo',
'c',
version: '0.1.0',
meson_version: '>= 0.59.0',
default_options: [
'warning_level=2',
'c_std=gnu11',
],
)

gtk_dep = dependency('gtk4')
adw_dep = dependency('libadwaita-1', version: '>= 1.4')
sqlite_dep = dependency('sqlite3')

subdir('src')