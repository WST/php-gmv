PHP_ARG_ENABLE(gmv, whether to enable gmv read extension,
[  --enable-gmv               Enable Gens movie reading support])

if test "$PHP_GMV" != "no"; then
	PHP_NEW_EXTENSION(gmv, gmv.c, $ext_shared)
fi
