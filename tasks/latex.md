# Efektywny LaTeX

Jedynym zastosowaniem LaTeXa gdzie jest rzeczywiście lepszy od alternatyw w postaci dokumentów Worda lub Markdowna/Asciidoc/ReStructuredText, jest przepiękna, ciesząca oko jak dobrze pokolorowana mapa, typografia. Jednak trzeba umieć jej używać, aby pliki źródłowe kompilowały się bez ostrzeżeń a rezultat był optymalny.

Używaj `\hbox` żeby powstrzymać dzielenie wyrazów, niedozwolone w nazwach własnych. `\mbox` tworzy sztuczny paragraf, jest niezalecany.
```tex
Był to wynalazek \hbox{Władimira} \hbox{Władimirovicza} \hbox{Władimirowa}.
```

Innym rozwiązaniem jest dodanie wyrazów do słownika wraz z poprawnym podzieleniem – więc aby powstrzymać dzielenie, można dodać je w całości. Przydaje się to z często używanymi wyrazami.
```tex
\hyphenation{Władimira Władimira}
\hyphenation{Władimirowicza Władimirowicza}
\hyphenation{Władimirowa Władimirowa}
Był to wynalazek Władimira Władimirowicza Władimirowa.
```

Używaj `~` aby nie zostawić wyrazu na końcu linii.
```tex
W polskim używamy tego przy krótkich spójnikach:
teizm i~antydysestabliszmentarianizm.
```

Używaj odpowiednich cudzysłowów. W polskim drugi poziom cudzysłowów to »x«, nie «x».
```tex
,,Wtedy powiedział >>To nie ja!<<.''
```

Włącz mikrotypografię. Mogą z nią być problemy jeżeli nie jest używany pdfLaTeX, wtedy można ją ewentualnie wyłączyć.
```tex
\usepackage{microtype}
```

Nie używaj `\newline` ani `\\` aby uzyskać odstępy – używaj `\medskip`. \
`\par` prawie nigdy nie jest potrzebny.
```tex
Paragraf nr 1, po którym jest odstęp.

\medskip

Paragraf nr 2.
```
