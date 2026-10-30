tempo_sources = [
  'main.c',
  'timer/tempo-timer-view.c'
]

tempo_deps =  [
  gtk_dep,
  adw_dep,
  sqlite_dep,
]

executable('tempo',
           tempo_sources,
           dependencies: tempo_deps,
           install: true,
          )
