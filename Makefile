limine:
	cd Limine && ./bootstrap
	cd Limine && ./configure
	$(MAKE) -C Limine
	$(MAKE) -C Limine install

.PHONY: limine