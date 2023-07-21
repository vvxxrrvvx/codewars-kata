using System.IO;

namespace Solution {
    class FileMaster {
        private string filepath;

        public FileMaster(string filepath) {
            this.filepath = filepath;
        }
        public string extension() {
            return Path.GetExtension(filepath).TrimStart('.');
        }
        public string filename() {
            return Path.GetFileNameWithoutExtension(filepath);
        }
        public string dirpath() {
            return Path.GetDirectoryName(filepath) + Path.DirectorySeparatorChar;
        }
    }
}