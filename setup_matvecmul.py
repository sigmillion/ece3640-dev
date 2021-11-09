from distutils.core import setup, Extension

def main():
    setup(name="matvecmul",
          version="1.0.0",
          description="Python interface for matrix-vector multiplication C library function",
          author="Jake",
          author_email="jake.gunther@usu.edu",
          ext_modules=[Extension("matvecmul", ["fmatvecmulmodule.c"])],
          define_macros=[('NPY_NO_DEPRECATED_API','NPY_1_7_API_VERSION')])

if __name__ == "__main__":
    main()
    
