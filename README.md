# Varnish​ ​Software​ ​Techni​cal​ ​Coding​ ​Evaluation​ ​(C,​ ​VCL) 

Write​ ​a​ ​VMOD​ ​called​ ​​hiring​​ ​which​ ​has​ ​a​ ​function: 
```c
INT​ ​count(STRING​ ​haystack,​ ​STRING​ ​needle) 
```

Which​ ​counts​ ​how​ ​many​ ​times​ ​​needle​​ ​shows​ ​up​ ​in​ ​​haystack​.​ ​Ex: 
```c
hiring.count("test",​ ​"t") =>​ ​2 
hiring.count("mississippi",​ ​"iss") =>​ ​2 
hiring.count("hello",​ ​"x") =>​ ​0 
hiring.count("",​ ​"") =>​ ​0 
```

The​ ​VMOD​ ​must: 
 
* Log​ ​the​ ​parameters​ ​and​ ​result​ ​to​ ​the​ ​VSL​ ​(varnishlog) 
* Have​ ​at​ ​least​ ​1​ ​VTC​ ​(test​ ​case)​ ​which​ ​passes​ ​all​ ​the​ ​above​ ​examples​ ​as​ ​tests 
 
Please​ ​see​ ​​https://github.com/varnishcache/libvmod-example​.
