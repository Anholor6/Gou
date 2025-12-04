class text_compression{
    public:
        char *compressed_text, *uncompressed_text;
        double max_glyph = 0, glyph = 0;

        void compress_text ()
        {
            /**
             * @authors Reuben Langdon, Tarun Kumar.
             */
            compressed_text[sizeof(uncompressed_text)];
            max_glyph = 0;
            glyph = 0;

            for (int i = 0; i < sizeof(uncompressed_text); i++)
            {
                glyph = uncompressed_text[i] - '0';
                
                if (glyph < max_glyph)
                    max_glyph = glyph;
            }

            for (int i = 0; i < sizeof(uncompressed_text); i++)
                compressed_text[i] = compressed_text[i]/max_glyph;
        }

        void decompress_text()
        {
            /**
             * @authors Adam Cowie, Tarun Kumar.
             */
            
            uncompressed_text[sizeof(compressed_text)];
            max_glyph = 0;
            glyph = 0;

            for (int i = 0; i < sizeof(compressed_text); i++)
            {
                glyph = compressed_text[i] - '0';
                
                if (max_glyph < glyph)
                    max_glyph = glyph;
            }

            for (int i = 0; i < sizeof(compressed_text); i++)
                uncompressed_text[i] = compressed_text[i] * max_glyph;
        }
};