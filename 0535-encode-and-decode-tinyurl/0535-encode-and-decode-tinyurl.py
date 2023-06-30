class Codec:

    def __init__(self):
        self.chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZ"

        self.long_to_short_dict = defaultdict()
        self.short_to_long_dict = {}

    def encode(self, long_url: str) -> str:
  
      # generate the short code of len 6
      while long_url not in self.long_to_short_dict:
        new_url_code = "".join(random.choices(self.chars, k=6)) # len is 6
        if new_url_code not in self.short_to_long_dict:
          self.long_to_short_dict[long_url]=new_url_code
          self.short_to_long_dict[new_url_code] = long_url

      return 'http://tinyurl.com/' + self.long_to_short_dict[long_url]

    def decode(self, short_url: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        url_code = short_url[-6:]
        return self.short_to_long_dict[url_code] # the code is the key and value is the long url
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))