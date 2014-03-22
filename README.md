# GMV support for PHP

Just for fun PHP extension for reading Gens input files. I wrote it because it seemed easier to write a dynamic extension than to deal with PHP’s unpack() or even regular expressions for so simple task as reading a structure from a binary file. I’ll probably use this if I decide to make a gmv hosting.

Installation:

```bash
git clone https://github.com/WST/php-gmv.git
cd php-gmv
phpize
./configure
make
```

For a Python version, use [python-gmv](https://github.com/WST/python-gmv) instead.

## What the hell is a Gens movie?

Gens movies are the files storing the input used to make a tool-assisted speedrun of a Sega game. You don’t need to deal with this extension if you have no idea what tool-assisted speedrunning is.
