# php-gmv

Just for fun PHP extension for reading Gens input files. I wrote it because it seemed easier to write a dynamic extension than to deal with PHP’s unpack() or even regular expressions for so simple task as reading a structure from a binary file. I’ll probably use this if I decide to make a gmv hosting.

Installation:

```bash
git clone https://github.com/WST/php-gmv.git
cd php-gmv
phpize
./configure
make
```