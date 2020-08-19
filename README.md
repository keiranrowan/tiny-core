# Tiny Core

Simple versions of coreutils and common linux commands written in C. Tiny may be a misnomer as my goal isn't an arbitrarily low line count or extreme independence
from the standard library, but rather only implementing the basic features. Bells and whistles may be seperated into their own commands depending on their noteworthiness.
These utilities are not meant to be a comprehensive rewrite of the GNU CoreUtils, but more as an exercise for myself using the C language. Feel free to fork, 
download, critique, or share any of these utilities. My goal is to have each utility follow the same general principle as far as command line usage:
```-``` for stdin and short flags for most options although there may be exceptions. ```-h``` and ```--help``` will 
show the help prompt for every command. Binaries are included in the repository since they aren't large by any means.

# Commands

## cat

### Usage

```bash
$ cat [FILE]...
```

This one left it's flags at Berkeley.

## wc

### Usage

```bash
$ wc [-h|-w|-c|-l|-b] [FILE]...
```
```-w``` prints word count. Uses the same definition as GNU wc: any non-zero length sequence of characters seperated by whitespace.

```-c``` prints character count.

```-l``` prints line count. ```\n``` is the newline delimiter.

```-b``` prints byte count. 1 character = 1 byte. Includes spaces and special characters.

