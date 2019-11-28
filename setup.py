# -*- coding: utf-8 -*-



from setuptools import setup, find_packages


with open('README.md') as f:
    readme = f.read()

with open('LICENSE') as f:
    license = f.read()

setup(
    name='sample',
    version='0.1.0',
    description='Sample package for Python-Guide.org',
    long_description=readme,
    author='Md Moin Uddin',
    author_email='eee.moin@gmail.com',
    url='https://github.com/moin59/Intelligent_Coffee_Machine',
    license=license,
    packages=find_packages(exclude=('source'))
)

