# The Eurace@Unibi Migration Model

Version: January 2018

This is the source code of the Eurace@Unibi Migration Model. The Model is a slighly extended two-region setup of the [EURACE@Unibi](http://www.wiwi.uni-bielefeld.de/lehrbereiche/vwl/etace/Eurace_Unibi/) model. We use the model to study the economic impact of a sizable level of forced migration into two countries that form a political and currency union. We consider the case in which the origin of migration is outside the union and immigrants exhibit skill levels that are on average considerably lower compared to the skill levels of the domestic labor force in both member states of the union. We assume that these skill gaps constitute a significant hurdle for integrating migrant workers into the labor market. Moreover, we assume that the two countries differ regarding their institutional setting, in particular with respect to the labor market,
and they differ regarding the production technology operated by frms in the countries resulting in different levels of productivity and economic activity. In simulation experiments, we examine the effect of different schemes of allocating migrants among the two countries, and analyze the effectiveness and implications of different policy measures aimed at fostering the integration of immigrants into the labor market.

**Dependencies**

GCC 4.4 or higher (or other C compiler)

GSL 2.4 or higher (GNU  Scientific  Library)

FLAME XParser 0.17.1 (https://github.com/FLAME-HPC/xparser/archive/0.17.1.tar.gz)

FLAME Libmboard 0.3.1 (https://github.com/FLAME-HPC/libmboard/archive/0.3.1.zip)

## Installation of FLAME libraries on stand-alone systems and building the model

Step 2-4 (installation of FLAME libraries) can also be run via a script
`./scripts/install_flame.sh`.

### 1. Prepare system requirements

Make sure to have `cunit` and `gsl` installed.
- On Debian-based systems: `sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev libgsl-dev`.
- On macOS: `brew install cunit gsl`.
- On Windows (TODO: test on appveyor): `TODO`.

### 2. Install libmboard

On top of the repo root directory, download libmboard 0.3.1
(https://github.com/FLAME-HPC/libmboard/archive/0.3.1.tar.gz) and extract the tarball

```bash
mkdir libmboard
cd libmboard-0.3.1
chmod +x autogen.sh
./autogen.sh
# Remove --disable-parallel if you have mpi installed
./configure --prefix=$(cd ../libmboard; pwd) --disable-parallel
make
make install
# back to the repo root directory
cd ..
```

### 3. Install xparser

Download xparser 0.17.1 (https://github.com/FLAME-HPC/xparser/archive/0.17.1.tar.gz) and
extract to xparser/ directory on top of the repo root directory.
```bash
cd xparser
make
# back to the repo root directory
cd ..
```

### 4. Generate makefile for the model
```bash
cd xparser
./xparser ../eurace_model.xml
# back to the repo root directory
cd ..
```

### 5. Build the model

Be sure to replace LIBMBOARD_DIR in Makefile from `/usr/local` to
`$(PWD)/libmboard`.
Finally, run `make`, which should compile everything if the previous steps are
executed correctly.

## Authors

Philipp Harting, Dirk Kohlweyer

## Further Links:

* [Harting and Kohlweyer 2018](http://www.isigrowth.eu/wp-content/uploads/2018/06/working_paper_2018_12.pdf) - Harting, P., Kohlweyer, D. (2018). Integrating Forced Migrants in a Union of Diverging Regions: A Policy Assessment
* [ETACE](http://www.wiwi.uni-bielefeld.de/lehrbereiche/vwl/etace/) - Chair for Economic Theory and Computational Economics
* [EURACE@Unibi](http://www.wiwi.uni-bielefeld.de/lehrbereiche/vwl/etace/Eurace_Unibi/) - description of the EURACE@Unibi model
* [Dawid et al. 2019](https://pub.uni-bielefeld.de/record/2915598) - Dawid, H., Harting, P., van der Hoog, S., & Neugart, M. (2019). Macroeconomics with heterogeneous agent models: Fostering transparency, reproducibility and replication. Journal of Evolutionary Economics.