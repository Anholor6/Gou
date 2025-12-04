class audio_compression{
    public:
        double *compressed_audio, *uncompressed_audio, max_audio_level = 0;

        void compress_audio()
        {
            for (int i = 0; i < sizeof(uncompressed_audio); i++)
            {
                /**
                 * @author Reol Nakamura, Tarun Kumar.
                 */
                if (uncompressed_audio[i] >= max_audio_level)
                    max_audio_level = uncompressed_audio[i]; //This is for the meanwhile.
            }

            compressed_audio[sizeof(uncompressed_audio)];

            for (int i = 0; i < sizeof(uncompressed_audio); i++)
                compressed_audio[i] = uncompressed_audio[i]/max_audio_level;
        }

        void decompress_audio()
        {
            for (int i = 0; i < sizeof(uncompressed_audio); i++)
            {
                /**
                 * @author Reol Nakamura, Tarun Kumar.
                 */
                if (uncompressed_audio[i] >= max_audio_level)
                    max_audio_level = compressed_audio[i]; //This is for the meanwhile.
            }

            uncompressed_audio[sizeof(compressed_audio)];

            for (int i = 0; i < sizeof(uncompressed_audio); i++)
                uncompressed_audio[i] = compressed_audio[i] * max_audio_level;
        }

        void empty_buffers()
        {
            /**
             * @authors Reol Nakamura, Tarun Kumar.
             */
            for (int i = 0; i < sizeof(compressed_audio); i++)
                compressed_audio[i] = 0;
            for (int i = 0; i < sizeof(uncompressed_audio); i++)
                uncompressed_audio[i] = 0;
            max_audio_level = 0;
        }
};