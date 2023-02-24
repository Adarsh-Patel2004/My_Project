all: libraries maxchain subwords

libraries:
	$(MAKE) -C trie/
	$(MAKE) -C util/

maxchain:
	$(MAKE) -C apps/ maxchain

subwords:
	$(MAKE) -C apps/ subwords

clean:
	$(MAKE) -C trie/ clean
	$(MAKE) -C util/ clean
	$(MAKE) -C apps/ clean